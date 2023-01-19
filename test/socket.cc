#define BOOST_VARIANT_USE_RELAXED_GET_BY_DEFAULT
#include <gtest/gtest.h>

#include "approval/ApprovalTests.hpp"
#include "nvim.h"

TEST(SOCKET, CONNECT) {
  nvim::Nvim nvim;
  nvim.Connect("localhost", "6666");
}

TEST(SOCKET, WRITE) {
  nvim::Nvim nvim;
  nvim.Connect("localhost", "6666");
  std::cout << "get_current_line = " << nvim.nvim_get_current_line()
            << std::endl;
}
