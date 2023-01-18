enable_testing()

add_executable(test test.cc)

target_link_libraries(test neovim-cc)
