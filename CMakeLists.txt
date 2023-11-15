cmake_minimum_required(VERSION 3.26)
project(rcutils C)

set(CMAKE_C_STANDARD 11)

add_executable(rcutils main.c
        src/collection/rc_list.c
        src/include/rc_list.h
        src/memory/rc_memory.c
        src/include/rc_memory.h
)
