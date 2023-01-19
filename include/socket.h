#ifndef NEOVIM_CC__SOCKET_H_
#define NEOVIM_CC__SOCKET_H_

#include <boost/asio.hpp>
#include <boost/date_time/posix_time/ptime.hpp>
#include <cstdlib>
#include <iostream>
#include <string>

namespace nvim {
class Socket {
 public:
  Socket() : socket(io_context), deadline(io_context) {
    deadline.expires_at(boost::posix_time::pos_infin);
    Tick();
  }

  void Connect(const std::string &host, const std::string &service,
               double timeout_sec);

  size_t Read(char *rbuf, size_t capacity, double timeout_sec);
  void Write(const char *sbuf, size_t opacity, double timeout_sec);

  void Close();

private:
  void Tick();

 private:
  boost::asio::io_context io_context;
  boost::asio::ip::tcp::socket socket;
  boost::asio::deadline_timer deadline;
};
}  // namespace nvim

#endif  // NEOVIM_CPP__SOCKET_HPP_
