enable_testing()
include(GoogleTest)

add_executable(socket-test socket.cc)
target_link_libraries(socket-test neovim-cc gtest gtest_main)
