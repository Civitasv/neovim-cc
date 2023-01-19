add_library(neovim-cc socket.cc)

find_package(Boost 1.80.0 REQUIRED COMPONENTS system coroutine context thread)

target_link_libraries(neovim-cc msgpackc-cxx ${Boost_LIBRARIES})

target_include_directories(
  neovim-cc PUBLIC ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/vendor
                   ${Boost_INCLUDE_DIR})
