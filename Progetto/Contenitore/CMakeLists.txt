cmake_minimum_required(VERSION 3.15)
project(Contenitore)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_executable(Contenitore main.cpp)