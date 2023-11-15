//
// Created by roberto on 11/14/23.
//

#ifndef RCUTILS_RC_MEMORY_H
#define RCUTILS_RC_MEMORY_H

#include <stdio.h>
#include <stdlib.h>

static size_t totalAllocated = 0;
static size_t totalFreed = 0;

/**
 * Custom malloc wrapper function.
 * Allocates memory of the specified size and tracks the allocated memory.
 *
 * @param size The size of memory to allocate in bytes.
 * @return A pointer to the allocated memory. Returns NULL if allocation fails.
 */
void *memory_malloc(size_t size);

/**
 * Custom free wrapper function.
 * Frees allocated memory pointed to by ptr and tracks the freed memory.
 *
 * @param ptr Pointer to the memory to be freed. If NULL, no action is taken.
 * @param size The size of the memory block being freed in bytes.
 * Note: The user must ensure that 'size' correctly corresponds to the size of the memory block.
 */
void memory_free(void *ptr, size_t size);

/**
 * Prints the current memory usage statistics.
 * Displays the total allocated memory, total freed memory, and net memory usage.
 * Net memory usage is calculated as totalAllocated - totalFreed.
 */
void memory_print_usage(const char *custom_marker);

#endif //RCUTILS_RC_MEMORY_H
