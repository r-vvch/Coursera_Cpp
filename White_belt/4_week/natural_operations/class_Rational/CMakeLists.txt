cmake_minimum_required(VERSION 3.21)
project(class_Rational)

set(CMAKE_CXX_STANDARD 14)

add_executable(rational_interface rational_interface.cpp)
add_executable(rational_eq_add_sub rational_eq_add_sub.cpp)
add_executable(rational_mult_div rational_mult_div.cpp)
add_executable(rational_io rational_io.cpp)
add_executable(rational_map rational_map.cpp)
add_executable(rational rational.cpp)
