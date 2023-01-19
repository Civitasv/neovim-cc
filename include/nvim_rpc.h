#ifndef NEOVIM_CC__NVIM_RPC_H_
#define NEOVIM_CC__NVIM_RPC_H_

#include <iostream>
#include <sstream>
#include <string>

#include "msgpack.hpp"
#include "socket.h"
#include "type.h"

namespace nvim {
namespace detail {
using Packer = msgpack::packer<msgpack::sbuffer>;

template <typename T>
Packer &pack(Packer &pk, const T &t) {
  return pk << t;
}

template <typename T1, typename T2, typename... T3>
Packer &pack(Packer &pk, const T1 &t1, const T2 &t2, const T3 &...t3) {
  return pack(pack(pk, t1), t2, t3...);
}

static Packer &pack(Packer &pk) { return pk; }
}  // namespace detail

class NvimRPC {
  enum { REQUEST = 0, RESPONSE = 1, NOTIFY = 2 };

 public:
  NvimRPC() : msgid_(0) {}

  void Connect(const std::string &host, const std::string &service,
               double timeout_sec) {
    socket_.Connect(host, service, timeout_sec);
  }

  template <typename T, typename... U>
  void call(const std::string &method, T &res, const U &...u) {
    Variant v = do_call(method, u...);
    std::cout << "T NvimRPC::call" << std::endl;

    res = boost::get<T>(v);
  }

  template <typename... U>
  void call(const std::string &method, int64_t &res, const U &...u) {
    Variant v = do_call(method, u...);
    std::cout << "Integer NvimRPC::call" << std::endl;

    // int64_t is only for negative integer.
    if (v.is_int64_t())
      res = v.as_int64_t();
    else if (v.is_uint64_t())
      res = v.as_uint64_t();
    else
      std::cout << "invalid response type" << std::endl;  // TODO: add error
                                                          // handler
  }

  template <typename... U>
  void call(const std::string &method, Variant &res, const U &...u) {
    Variant v = do_call(method, u...);
    std::cout << "Object NvimRPC::call" << std::endl;
    res = v;
  }

  template <typename... U>
  void call(const std::string &method, std::nullptr_t res, const U &...u) {
    do_call(method, u...);
    std::cout << "void NvimRPC::call" << std::endl;
  }

 private:
  template <typename... U>
  Variant do_call(const std::string &method, const U &...u) {
    msgpack::sbuffer sbuf;
    detail::Packer pk(&sbuf);

    pk.pack_array(4) << (uint64_t)REQUEST << msgid_++ << method;
    pk.pack_array(sizeof...(u));

    detail::pack(pk, u...);

    msgpack::object_handle oh = msgpack::unpack(sbuf.data(), sbuf.size());
    msgpack::object deserialized = oh.get();
    std::cout << "sbuf = " << deserialized << std::endl;

    socket_.Write(sbuf.data(), sbuf.size(), 1);

    msgpack::unpacker unpacker;
    unpacker.reserve_buffer(32 * 1024ul);

    size_t rlen =
        socket_.Read(unpacker.buffer(), unpacker.buffer_capacity(), 10);

    msgpack::unpacked result;
    unpacker.buffer_consumed(rlen);
    unpacker.next(result);

    const msgpack::object &obj = result.get();
    std::cout << "res = " << obj << std::endl;
    msgpack::type::tuple<int64_t, int64_t, Variant, Variant> dst;
    obj.convert(dst);
    return dst.get<3>();
  }

  uint64_t msgid_;
  Socket socket_;
};
}  // namespace nvim

#endif  // NEOVIM_CPP__NVIM_RPC_HPP_
