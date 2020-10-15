cmake_minimum_required(VERSION 3.18)
project(consistenthash)

set(CMAKE_CXX_STANDARD 14)

set_target_properties(${TARGET} PROPERTIES COMPILE_FLAGS "-pthread" LINK_FLAGS "-pthread")


add_executable(consistenthash main.cpp ConsistentHash.cpp ConsistentHash.h  md5.cpp md5.h)