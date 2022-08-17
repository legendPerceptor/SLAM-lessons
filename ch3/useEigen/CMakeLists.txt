cmake_minimum_required(VERSION 3.16)

project(HelloSLAM)

set(CMAKE_BUILD_TYPE "Debug")

include_directories("/usr/include/eigen3")

add_executable(eigenMatrix eigenMatrix.cpp)

add_executable(useGeometry useGeometry.cpp)

add_executable(coordinateTransform coordinateTransform.cpp)