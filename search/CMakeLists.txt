cmake_minimum_required(VERSION 3.18)
project(search)

set(CMAKE_CXX_STANDARD 14)

set_target_properties(${TARGET} PROPERTIES COMPILE_FLAGS "-pthread" LINK_FLAGS "-pthread")

include_directories(test/lib/googletest/googletest/include)

add_subdirectory(test/lib/googletest)

add_executable(search Search.cpp Search.h)

target_link_libraries(search gtest gtest_main)