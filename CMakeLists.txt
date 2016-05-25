cmake_minimum_required(VERSION 3.5)
project(Fraction)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp util/fraction.h util/fraction.cpp)
add_executable(Fraction ${SOURCE_FILES})