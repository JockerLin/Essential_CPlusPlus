cmake_minimum_required(VERSION 3.14)
project(codes)

set(CMAKE_CXX_STANDARD 14)
add_executable(codes main.cpp swap.cpp
        chp1/chp1.cpp
        chp2/chp2.h chp2/chp2_5.cpp chp2/chp2_6.cpp
        chp3/chp3.h chp3/chp3_1.cpp chp3/chp3_2.cpp chp3/chp3_3.cpp chp3/chp3_4.cpp
        chp4/chp4.h chp4/shp4_1.cpp chp4/static_func.cpp chp4/chp4_2.cpp chp4/chp4_4.cpp
        chp4/operate_reload.cpp chp4/chp4_5.cpp)
