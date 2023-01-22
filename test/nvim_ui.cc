#include <gtest/gtest.h>

#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/signal_set.hpp>
#include <iostream>

#include "msgpack.hpp"
#include "nvim_rpc.h"
#include "renderer.h"

TEST(A, B) {
  try {
    boost::asio::io_context io_context(1);
    boost::asio::signal_set signals(io_context, SIGINT, SIGTERM);

    signals.async_wait([&](auto, auto) {
      std::cout << "HERE" << '\n';
      io_context.stop();
    });

    boost::asio::ip::tcp::socket socket{io_context};
    socket.connect({boost::asio::ip::address::from_string("127.0.0.1"), 6666});

    nvim::NvimRPC rpc(io_context, socket);

    Renderer renderer(&rpc);
    renderer.AttachUI();

    io_context.run();
  } catch (std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }
}
