cmake_minimum_required(VERSION 3.0)
project(RTChallenge VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(DEPS_DIR ${RTChallenge_SOURCE_DIR}/deps)

add_subdirectory(tests)
