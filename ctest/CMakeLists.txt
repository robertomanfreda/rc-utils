cmake_minimum_required(VERSION 3.14.0 FATAL_ERROR)

set(UTILS
        t_utils.h
        t_utils.c
)

# Test for rc_list
add_executable(test_rc_list t_rc_list.c ${UTILS})
target_link_libraries(test_rc_list rcutils_lib)
add_test(NAME RcListTest COMMAND test_rc_list)

# Test for rc_memory
add_executable(test_rc_memory t_rc_memory.c ${UTILS})
target_link_libraries(test_rc_memory rcutils_lib)
add_test(NAME RcMemoryTest COMMAND test_rc_memory)

enable_testing()