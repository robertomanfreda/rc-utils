//
// Created by roberto on 11/14/23.
//

#include "../include/rc_memory.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *memory_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr != NULL) {
        totalAllocated += size;
    }
    return ptr;
}

void memory_free(void *ptr, size_t size) {
    if (ptr != NULL) {
        totalFreed += size;
    }

    free(ptr);
}

void memory_print_usage(const char *custom_marker) {
    const char *msg = "-------------- Memory Report: %s --------------";
    printf(msg, custom_marker);
    printf("\n");
    printf(" + Total Allocated Memory: %zu bytes\n", totalAllocated);
    printf(" + Total Freed Memory: %zu bytes\n", totalFreed);
    printf(" + Net Memory Usage: %zu bytes\n", totalAllocated - totalFreed);
    for (size_t i = 0; i < strlen(msg) + strlen(custom_marker) - 2; i++) {
        printf("-");
    }
    printf("\n");
}