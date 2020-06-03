cmake_minimum_required(VERSION 3.15)
project(libxtl)

set(CMAKE_CXX_STANDARD 17)
include_directories(.)
add_library(libxtl SHARED general.h TensorRef.h fillcopy.h fillcopy.cpp general.cpp binary_func.h binary_func.cpp)