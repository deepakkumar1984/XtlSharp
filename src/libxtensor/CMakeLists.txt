cmake_minimum_required(VERSION 3.15)
project(libxtensor)

set(CMAKE_CXX_STANDARD 17)
include_directories(.)
add_library(xtensor SHARED general.h TensorRef.h fillcopy.h fillcopy.cpp general.cpp)