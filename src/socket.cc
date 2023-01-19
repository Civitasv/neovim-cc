#include "socket.h"

#include <boost/asio/error.hpp>
#include <boost/asio/read.hpp>
#include <boost/asio/write.hpp>
#include <boost/lambda/bind.hpp>
#include <boost/lambda/lambda.hpp>

namespace nvim {
using namespace boost;
using boost::asio::deadline_timer;
using boost::asio::ip::tcp;
using boost::lambda::_1;
using boost::lambda::bind;
using boost::lambda::var;

void Socket::Connect(const std::string& host, const std::string& service,
                     double timeout_sec) {
  deadline.expires_from_now(posix_time::seconds((int)timeout_sec));

  tcp::resolver resolver(io_context);
  auto endpoints = resolver.resolve(host, service);

  system::error_code ec = asio::error::would_block;
  asio::async_connect(
      socket, endpoints,
      [&ec](system::error_code error_code, tcp::endpoint) { ec = error_code; });
  do io_context.run_one();
  while (ec == asio::error::would_block);

  if (!ec) {
    // std::cout << "Connect successful!" << '\n';
    return;
  }
  throw system::system_error(ec ? ec : asio::error::host_not_found);
}

size_t Socket::Read(char* rbuf, size_t capacity, double timeout_sec) {
  deadline.expires_from_now(posix_time::seconds((int)timeout_sec));

  system::error_code ec = asio::error::would_block;
  size_t rlen;

  asio::async_read(socket, asio::buffer(rbuf, capacity),
                   asio::transfer_at_least(1),
                   [&ec, &rlen](system::error_code e, size_t s) {
                     ec = e;
                     rlen = s;
                   });

  do io_context.run_one();
  while (ec == asio::error::would_block);

  if (!ec) {
    // std::cout << "Read successful!" << '\n';
    return rlen;
  }
  throw system::system_error(ec);
}

void Socket::Write(const char* sbuf, size_t opacity, double timeout_sec) {
  deadline.expires_from_now(posix_time::seconds((int)timeout_sec));

  system::error_code ec = asio::error::would_block;
  asio::async_write(socket, asio::buffer(sbuf, opacity), var(ec) = _1);

  do io_context.run_one();
  while (ec == asio::error::would_block);

  if (!ec && socket.is_open()) {
    // std::cout << "Write successful!" << '\n';
    return;
  }
  throw system::system_error(ec);
}

void Socket::Tick() {
  if (deadline.expires_at() <= deadline_timer::traits_type::now()) {
    socket.close();
    deadline.expires_at(boost::posix_time::pos_infin);
  }

  deadline.async_wait(bind(&Socket::Tick, this));
}
}  // namespace nvim
