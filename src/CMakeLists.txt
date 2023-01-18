add_library(neovim-cc socket.cc)

find_package(Boost 1.80.0 REQUIRED COMPONENTS system coroutine context thread)

target_link_libraries(neovim-cc ${Boost_LIBRARIES} msgpackc-cxx)

target_include_directories(
  neovim-cc PUBLIC ${CMAKE_SOURCE_DIR}/include ${Boost_INCLUDE_DIR}
                   ${CMAKE_SOURCE_DIR}/vendor)
