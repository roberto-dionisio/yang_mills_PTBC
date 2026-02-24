cmake_minimum_required(VERSION 3.10)
project(yang_mills_sun_cuda LANGUAGES C CXX CUDA)

set(CMAKE_CUDA_STANDARD 11)

include_directories(include)

set(SOURCES
    src/starting_point.c
    src/gpu_backend.cu
    src/gpu_kernels.cu
)


add_executable(yang_mills_sun_cuda ${SOURCES})


target_link_libraries(yang_mills_sun_cuda)