cmake_minimum_required(VERSION 3.26)
project(rcutils C)

set(CMAKE_C_STANDARD 11)

add_executable(rcutils main.c
        src/collection/list.c
        src/include/list.h
        src/memory/memory_wrapper.c
        src/include/memory_wrapper.h
)
