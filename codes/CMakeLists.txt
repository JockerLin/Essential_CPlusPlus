cmake_minimum_required(VERSION 3.14)
project(codes)

set(CMAKE_CXX_STANDARD 14)
add_executable(codes main.cpp swap.cpp
        chp2/chp2.h chp2/chp2_5.cpp chp2/chp2_6.cpp
        chp3/chp3.h chp3/chp3_1.cpp chp3/chp3_2.cpp chp3/chp3_3.cpp)