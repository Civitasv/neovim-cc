#include "socket.h"

#include <boost/asio/error.hpp>
#include <boost/asio/read.hpp>
#include <boost/asio/write.hpp>
#include <boost/lambda/bind.hpp>
#include <boost/lambda/lambda.hpp>

namespace nvim {
using namespace boost;
void Socket::Read(char* rbuf, size_t capacity, AfterRead after_read) {
  socket_.async_read_some(
      asio::buffer(rbuf, capacity),
      [after_read](const auto& err, size_t n) { after_read(err, n); });
}

void Socket::Write(const char* sbuf, size_t opacity, AfterWrite after_write) {
  asio::async_write(
      socket_, asio::buffer(sbuf, opacity),
      [after_write](const auto& err, size_t n) { after_write(err, n); });
}

void Socket::Close() { socket_.close(); }
}  // namespace nvim
