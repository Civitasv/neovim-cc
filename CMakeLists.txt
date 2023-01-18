cmake_minimum_required(VERSION 3.22)

project(neovim-cc)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(vendor/googletest)
add_subdirectory(vendor/fmt)

set(MSGPACK_BUILD_EXAMPLES OFF)
set(MSGPACK_BUILD_TESTS OFF)
set(MSGPACK_CXX17 ON)
add_definitions(-DMSGPACK_USE_BOOST)
add_subdirectory(vendor/msgpack-c)
