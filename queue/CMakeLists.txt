cmake_minimum_required(VERSION 3.16)
project(queue)

set(CMAKE_CXX_STANDARD 14)

include_directories(test/lib/googletest/googletest/include)

add_subdirectory(test/lib/googletest)

add_executable(queue ArrayQueue.cpp ArrayQueue.h test/array/TestArrayQueue.cpp LinkQueue.cpp LinkQueue.h test/link/TestLinkQueue.cpp CircleQueue.cpp CircleQueue.h test/circle/TestCircleQueue.cpp task/Produce.cpp task/Produce.h task/Comsumer.cpp task/Comsumer.h test/task/TestTask.cpp)

target_link_libraries(queue gtest gtest_main)