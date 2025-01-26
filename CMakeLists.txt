cmake_minimum_required(VERSION 3.29)
project(hw1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(hw1
    grade_split.cpp
    grade_ulliststr.cpp
    split.cpp
    split.h
    test_split.cpp
    test_ulliststr.cpp
    ulliststr.cpp
    ulliststr.h)
