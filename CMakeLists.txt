cmake_minimum_required(VERSION 3.17 FATAL_ERROR)
project(ml_cpp LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/libtorch/include)

file(GLOB _src src/*.cpp src/*.h include/*.h)

add_executable(${CMAKE_PROJECT_NAME} ${_src})
target_link_libraries(${CMAKE_PROJECT_NAME} ${OpenCV_LIBS})