enable_testing()
include(GoogleTest)

add_executable(nvim_ui nvim_ui.cc main.cc)
target_link_libraries(nvim_ui neovim-cc gtest gtest_main)
