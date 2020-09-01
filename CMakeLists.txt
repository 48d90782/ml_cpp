cmake_minimum_required(VERSION 3.17 FATAL_ERROR)
project(ml_cpp LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
find_package(OpenCV REQUIRED)

set(CUDNN_LIBRARY_PATH ${CMAKE_SOURCE_DIR}/external/cudnn/cuda/lib64/libcudnn.so)
set(CUDNN_INCLUDE_PATH ${CMAKE_SOURCE_DIR}/external/cudnn/cuda/include/)

include(${CMAKE_SOURCE_DIR}/external/libtorch/share/cmake/Torch/TorchConfig.cmake)
include_directories(${OpenCV_INCLUDE_DIRS})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/external/libtorch)

find_package(Torch REQUIRED)

file(GLOB _src src/*.cpp src/*.h include/*.h)

add_executable(${CMAKE_PROJECT_NAME} ${_src})
target_link_libraries(${CMAKE_PROJECT_NAME} ${TORCH_LIBRARIES} ${OpenCV_LIBS})