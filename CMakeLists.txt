cmake_minimum_required(VERSION 3.0)
project(tml)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(tml src/operation.cpp)

target_include_directories(tml PUBLIC "${PROJECT_SOURCE_DIR}/include/tml")