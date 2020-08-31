cmake_minimum_required(VERSION 3.17 FATAL_ERROR)
project(ml_cpp LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)

file(GLOB _src src/*.cpp src/*.h include/*.h)

add_executable(${CMAKE_PROJECT_NAME} ${_src})