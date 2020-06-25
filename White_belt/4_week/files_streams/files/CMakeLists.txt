cmake_minimum_required(VERSION 3.17)
project(files)

set(CMAKE_CXX_STANDARD 14)

#file(READ input.txt)
add_executable(files1 main1.cpp input.txt)
add_executable(files2 main2.cpp input.txt output.txt)