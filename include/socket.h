#ifndef NEOVIM_CC__SOCKET_H_
#define NEOVIM_CC__SOCKET_H_

#include <boost/asio.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/date_time/posix_time/ptime.hpp>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <string>

namespace nvim {
using AfterWrite = std::function<void(const boost::system::error_code, size_t)>;
using AfterRead = std::function<void(const boost::system::error_code, size_t)>;
class Socket {
 public:
  Socket(boost::asio::ip::tcp::socket &socket) : socket_(socket) {}

  void Read(char *rbuf, size_t capacity, AfterRead after_read);
  void Write(const char *sbuf, size_t opacity, AfterWrite after_write);

  void Close();

 private:
  boost::asio::ip::tcp::socket &socket_;
};
}  // namespace nvim

#endif  // NEOVIM_CPP__SOCKET_HPP_
