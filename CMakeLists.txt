cmake_minimum_required(VERSION 3.22)

project(neovim_client_cpp)

find_package(Boost 1.80.0 REQUIRED COMPONENTS system coroutine context thread)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "-DMSGPACK_USE_BOOST ${CMAKE_CXX_FLAGS}")

add_library(neovim-cc src/socket.cpp)

set(MSGPACK_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/msgpack-c)
add_subdirectory(${MSGPACK_SOURCE_DIR})
target_link_libraries(neovim-cc ${Boost_LIBRARIES} msgpackc-cxx)

target_include_directories(
  neovim-cc PUBLIC ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/gen
                   ${Boost_INCLUDE_DIR} ${MSGPACK_SOURCE_DIR}/include)

add_subdirectory(test)
# find_package(PythonInterp) if(PYTHONINTERP_FOUND) message("FOUNDED")
# add_custom_target( auto_gen_api COMMAND ${PYTHON_EXECUTABLE}
# ${CMAKE_SOURCE_DIR}/gen_api.py WORKING_DIRECTORY ${CMAKE_SOURCE_DIR} COMMENT
# "Autogen nvim interface") endif()
#
# add_dependencies(test auto_gen_api)
