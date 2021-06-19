cmake_minimum_required(VERSION 3.17)
project(files)

set(CMAKE_CXX_STANDARD 17)

add_executable(files main.cpp files.cpp utils.cpp downloads.cpp)