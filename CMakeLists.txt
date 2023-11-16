cmake_minimum_required(VERSION 3.26)
project(rcutils_lib C)

set(CMAKE_C_STANDARD 11)

# Add the include directory for header files
include_directories(src/include)

add_library(
        rcutils_lib
        src/collection/rc_list.c
        src/memory/rc_memory.c
)

target_link_libraries(rcutils_lib)

add_subdirectory(ctest)
enable_testing()