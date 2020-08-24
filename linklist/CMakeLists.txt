cmake_minimum_required(VERSION 3.16)
project(linklist)

set(CMAKE_CXX_STANDARD 14)


include_directories(test/lib/googletest/googletest/include)

add_subdirectory(test/lib/googletest)

add_executable(linklist SingleLink.cpp SingleLink.h test/sigle_link/TestSingle.cpp CircleLInk.cpp CircleLInk.h test/circle_link/TestCircle.cpp DoubleLink.cpp DoubleLink.h test/double_link/TestDouble.cpp Algorithm.cpp Algorithm.h test/algorithm/TestAlgorithm.cpp)


target_link_libraries(linklist gtest gtest_main)