#
# CMakeLists.txt (on /)
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

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./target)

message(STATUS "C++ Compiler flags: ${CMAKE_CXX_FLAGS} // ${CMAKE_CXX_STANDARD}")

add_executable(nsc nsc.cc)
