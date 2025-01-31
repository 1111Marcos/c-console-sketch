#
# CMakeLists.txt
#
# # On project /
# $ cmake -S . -B ./build -DCMAKE_CXX_COMPILER=clang++
# $ cd build && make
#
cmake_minimum_required(VERSION 3.22.0)

project(cc-console-sketch LANGUAGES CXX)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

if(CMAKE_BUILD_TYPE STREQUAL "Debug" OR
    CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG}")  # GNU C: -g
endif()

message(STATUS "C++ Compiler flags: ${CMAKE_CXX_FLAGS}")

add_executable(nsc nsc.cc)
