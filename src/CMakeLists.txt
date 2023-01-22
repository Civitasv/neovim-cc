add_library(neovim-cc socket.cc)

find_package(Boost 1.80.0 REQUIRED COMPONENTS system coroutine context thread)

target_link_libraries(neovim-cc msgpackc-cxx ${Boost_LIBRARIES})

find_package(Threads)
target_link_libraries(neovim-cc ${CMAKE_THREAD_LIBS_INIT} -lcurses)

target_include_directories(
  neovim-cc PUBLIC ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/vendor
                   ${Boost_INCLUDE_DIR})
