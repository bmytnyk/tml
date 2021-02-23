cmake_minimum_required(VERSION 3.0)
project(tml)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB CPP_SOURCES src/*.cpp)

file(GLOB HEADERS include/tml/*.h)

set(ALL_SOURCES ${CPP_SOURCES} ${HEADERS})

add_library(tml ${ALL_SOURCES})

target_include_directories(tml PUBLIC "${PROJECT_SOURCE_DIR}/include/tml")