cmake_minimum_required(VERSION 3.16)
project(stack)

set(CMAKE_CXX_STANDARD 14)

include_directories(test/lib/googletest/googletest/include)

add_subdirectory(test/lib/googletest)

add_executable(stack Stack.cpp Stack.h test/arraystack/TestArrayStack.cpp LinkStack.cpp LinkStack.h)

target_link_libraries(stack gtest gtest_main)