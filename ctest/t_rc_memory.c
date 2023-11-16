//
// Created by roberto on 11/16/23.
//

#include <assert.h>
#include <stdlib.h>
#include "rc_memory.h"
#include "t_utils.h"

void test_memory_malloc() {
    printf("Executing: %s\n", __func__);

    size_t size = 100;
    void *ptr = memory_malloc(size);

    assert(ptr != NULL);
    assert(memory_get_allocated() == size);

    free(ptr); // Use free directly since memory_malloc was used
}

void test_memory_free() {
    printf("Executing: %s\n", __func__);

    size_t size = 100;
    void *ptr = malloc(size); // Use malloc directly since memory_free will be tested

    assert(ptr != NULL);
    memory_free(ptr, size);

    assert(memory_get_freed() == size);
}

void test_memory_allocation_and_freeing() {
    printf("Executing: %s\n", __func__);

    size_t size = 100;
    void *ptr = memory_malloc(size);

    assert(ptr != NULL);
    memory_free(ptr, size);

    mem_check();
}

int main() {
    printf("Executing tests from file: %s\n\n", __FILE_NAME__);

    test_memory_malloc();
    test_memory_free();
    test_memory_allocation_and_freeing();

    printf("All memory management tests passed!\n");
    return 0;
}