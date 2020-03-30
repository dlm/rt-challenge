cmake_minimum_required(VERSION 3.0)
project(rt-challenge VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(TARGET ${PROJECT_NAME})
add_executable(${TARGET} main.cpp)
