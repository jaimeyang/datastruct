cmake_minimum_required(VERSION 3.16)
project(algorithm)

set(CMAKE_CXX_STANDARD 17)

set_target_properties(${TARGET} PROPERTIES COMPILE_FLAGS "-pthread" LINK_FLAGS "-pthread")

include_directories(test/lib/googletest/googletest/include)

add_subdirectory(test/lib/googletest)

add_executable(algorithm
        recall/EightQueens.cpp
        recall/EightQueens.h
        test/recall/TestEightQueens.cpp)

target_link_libraries(algorithm gtest gtest_main)