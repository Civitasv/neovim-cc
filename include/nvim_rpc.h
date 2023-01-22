#ifndef NEOVIM_CC__NVIM_RPC_H_
#define NEOVIM_CC__NVIM_RPC_H_

#include <boost/asio/write.hpp>
#include <functional>
#include <iostream>
#include <sstream>
#include <string>

#include "msgpack.hpp"
#include "socket.h"

namespace nvim {
using Packer = msgpack::packer<msgpack::sbuffer>;
using OnPackerRequest = std::function<void(Packer &)>;
using OnNotify =
    std::function<void(const std::string &, const msgpack::object &)>;
using OnResponse =
    std::function<void(const msgpack::object &, const msgpack::object &)>;

class NvimRPC {
  enum { REQUEST = 0, RESPONSE = 1, NOTIFY = 2 };

 public:
  NvimRPC(boost::asio::io_context &io_context,
          boost::asio::ip::tcp::socket &socket)
      : msgid_(0), io_context_(io_context), socket_{socket} {
    Dispatch();
  }

  void Request(OnPackerRequest on_packer_request, OnResponse on_response) {
    auto [it, _] = requests_.emplace(msgid_++, std::move(on_response));
    msgpack::sbuffer buffer;
    Packer pk(&buffer);
    pk.pack_array(4);
    pk.pack((int)REQUEST);
    pk.pack(it->first);
    on_packer_request(pk);
    socket_.Write(buffer.data(), buffer.size(),
                  [](const boost::system::error_code &werr, size_t wlen) {
                    std::cout << "AFTERWRITE";
                    CheckError(werr, wlen);
                  });
  }

  void Dispatch() {
    unpacker_.reserve_buffer(32 * 1024ul);
    socket_.Read(unpacker_.buffer(), unpacker_.buffer_capacity(),
                 [&](const boost::system::error_code &rerr, size_t rlen) {
                   CheckError(rerr, rlen);
                   if (!rlen) throw std::runtime_error("EOF");

                   std::cout << "RESULT" << '\n';
                   msgpack::unpacked result;
                   unpacker_.buffer_consumed(rlen);
                   while (unpacker_.next(result)) {
                     const msgpack::object &obj = result.get();
                     const auto &arr = obj.via.array;
                     // std::cout << "TYPE: " << arr.ptr[0] << '\n';
                     if (arr.ptr[0] == (int)RESPONSE) {
                       std::cout << "RESPONSE: " << arr.ptr[1] << '\n';
                       auto it = requests_.find(arr.ptr[1].as<uint64_t>());
                       it->second(arr.ptr[2], arr.ptr[3]);
                       requests_.erase(it);
                     } else if (arr.ptr[0] == (int)NOTIFY) {
                       std::cout << "NOTIFY: " << arr.ptr[1] << '\n';
                       on_notify_(arr.ptr[1].as<std::string>(), arr.ptr[2]);
                     }
                   }
                   Dispatch();
                 });
  }

 private:
  static void CheckError(const boost::system::error_code &err, size_t n) {
    if (err) {
      std::ostringstream oss;
      oss << err << std::endl;
      throw std::runtime_error(oss.str());
    }
    if (!n) throw std::runtime_error("EOF");
  }

 public:
  void SetOnNotify(OnNotify on_notify) { on_notify_ = on_notify; }

 private:
  Socket socket_;
  boost::asio::io_context &io_context_;
  msgpack::unpacker unpacker_;
  uint64_t msgid_;
  std::map<uint64_t, OnResponse> requests_;
  OnNotify on_notify_;
};
}  // namespace nvim

#endif  // NEOVIM_CPP__NVIM_RPC_HPP_
