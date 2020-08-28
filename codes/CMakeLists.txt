cmake_minimum_required(VERSION 3.14)
project(codes)

set(CMAKE_CXX_STANDARD 14)
add_executable(codes main.cpp swap.cpp
        book_practices/chp1/chp1.cpp
        book_practices/chp2/chp2.h book_practices/chp2/chp2.cpp book_practices/chp2/chp2_5.cpp book_practices/chp2/chp2_6.cpp
        book_practices/chp3/chp3.h book_practices/chp3/chp3_1.cpp book_practices/chp3/chp3_2.cpp
        book_practices/chp3/chp3_3.cpp book_practices/chp3/chp3_4.cpp book_practices/chp4/chp4.h
        book_practices/chp4/shp4_1.cpp book_practices/chp4/static_func.cpp book_practices/chp4/chp4_2.cpp
        book_practices/chp4/chp4_3.h book_practices/chp4/chp4_4.cpp
        book_practices/chp4/operate_reload.cpp book_practices/chp4/chp4_5.cpp book_practices/chp5/chp5.h
        book_practices/chp5/virtualfunc.cpp book_practices/chp5/chp5_1.cpp book_practices/classdemo/pointclass.cpp
        book_practices/classdemo/pointclass.h
        book_practices/chp6/chp6.h book_practices/chp6/chp6_1.cpp book_practices/chp6/chp6_2.cpp book_practices/chp7/chp7.h book_practices/chp7/chp7.cpp)
