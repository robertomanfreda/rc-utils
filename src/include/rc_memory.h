//
// Created by roberto on 11/14/23.
//

#ifndef RCUTILS_RC_MEMORY_H
#define RCUTILS_RC_MEMORY_H

#include <stdio.h>
#include <stdlib.h>

/**
 * Tracks the total amount of memory allocated.
 */
static size_t totalAllocated = 0;

/**
 * Tracks the total amount of memory freed.
 */
static size_t totalFreed = 0;

/**
 * Custom implementation of malloc.
 * Allocates memory of the specified size and updates the total allocated memory counter.
 *
 * @param size Size of the memory block to allocate, in bytes.
 * @return Pointer to the allocated memory block, or NULL if allocation fails.
 */
void *memory_malloc(size_t size);

/**
 * Custom implementation of free.
 * Frees the memory block pointed to by ptr and updates the total freed memory counter.
 *
 * @param ptr Pointer to the memory block to be freed. If NULL, no action is taken.
 * @param size Size of the memory block being freed, in bytes.
 *        It is the responsibility of the caller to ensure that the size is correct.
 */
void memory_free(void *ptr, size_t size);

/**
 * Outputs current memory usage statistics to standard output.
 * Displays total allocated memory, total freed memory, and the net memory usage
 * (calculated as totalAllocated - totalFreed).
 *
 * @param customMarker A custom string or identifier that can be prepended to the output for easy identification.
 */
void memory_print_usage(const char *customMarker);

/**
 * Retrieves the total amount of memory allocated.
 *
 * @return Total amount of allocated memory, in bytes.
 */
size_t memory_get_allocated();

/**
 * Retrieves the total amount of memory freed.
 *
 * @return Total amount of freed memory, in bytes.
 */
size_t memory_get_freed();


#endif //RCUTILS_RC_MEMORY_H
