cmake_minimum_required(VERSION 3.18)
project(sort)

set(CMAKE_CXX_STANDARD 14)

set_target_properties(${TARGET} PROPERTIES COMPILE_FLAGS "-pthread" LINK_FLAGS "-pthread")

include_directories(test/lib/googletest/googletest/include)

add_subdirectory(test/lib/googletest)

add_executable(sort Sort.cpp Sort.h test/lib/sort/TestSort.cpp)

target_link_libraries(sort gtest gtest_main)