//
// Created by roberto on 11/10/23.
//

#ifndef RCUTILS_LIST_H
#define RCUTILS_LIST_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct NodeList NodeList;

struct NodeList {
    int data;
    NodeList *previous;
    NodeList *next;
};

typedef struct {
    size_t size;
    NodeList *head;
} List;

/**
 * Creates a new list and initializes its size and head.
 *
 * @return a pointer to the newly created list.
 */
List *list_create();

/**
 * Creates a deep copy of the provided list.
 * Each element of the source list is copied to a new list.
 *
 * @param source A pointer to the list to be copied.
 * @return A pointer to the newly created list which is a deep copy of the source list.
 *         Returns NULL if the source list is NULL or if memory allocation fails.
 */
List *list_deep_copy(const List *source);

/**
 * Frees the memory allocated for the list and all its nodes.
 *
 * @param list a pointer to the list to be destroyed.
 */
void list_destroy(List *list);

/**
 * Clears the contents of the provided list and re-initializes it.
 * The function frees all the nodes in the list and then creates a new, empty list.
 *
 * @param list A pointer to a pointer to the list. This allows the function
 *             to modify the caller's list pointer directly.
 *             If the pointer to the list or the list itself is NULL, the function does nothing.
 */
void list_clear(List **list);

/**
 * Appends a new node with the given data to the end of the list.
 *
 * @param list a pointer to the list where to append data.
 * @param data the data to be appended.
 */
void list_append(List *list, int data);

/**
 * Inserts a new node with the given data at the beginning of the list.
 *
 * @param list a pointer to the list where to prepend data.
 * @param data the data to be appended.
 */
void list_prepend(List *list, int data);

/**
 * Checks if the provided list is empty.
 * An empty list is defined as one whose head pointer is NULL,
 * indicating that it contains no elements.
 *
 * @param list A pointer to the list to be checked. It should not be NULL.
 * @return Returns true if the list is empty (i.e., has no elements),
 *         false otherwise.
 */
bool list_is_empty(const List *list);

/**
 * Checks if the provided list is not empty.
 * A non-empty list is defined as one whose head pointer is not NULL,
 * indicating that it contains at least one element.
 *
 * @param list A pointer to the list to be checked. It should not be NULL.
 * @return Returns true if the list is not empty (i.e., has one or more elements),
 *         false if it is empty.
 */
bool list_is_not_empty(const List *list);

/**
 * Reverses the order of the nodes in the provided list.
 * The head of the list becomes the tail and vice versa.
 *
 * @param list A pointer to the list to be reversed.
 */
void list_reverse(List *list);

/**
 * Prints the data of each node in the list.
 *
 * @param list a pointer to the list to be printed.
 */
void list_print(const List *list);

/**
 * Retrieves the size (number of elements) of the provided list.
 * If the list is NULL or empty, an error message is printed and 0 is returned.
 *
 * @param list A pointer to the list whose size is to be retrieved.
 * @return The number of elements in the list.
 *         Returns 0 if the list is NULL or empty.
 */
size_t list_get_size(const List *list);

/**
 * Returns the last node in the list.
 *
 * @param list pointer to the list.
 * @return NULL if the list is empty or the last NodeList pointer.
 */
static NodeList *list_get_last_node(const List *list);
/*

 // Insertion
void list_insert_at_index(List *list, int value, size_t index);


// Retrieval
int list_get_head(List *list);

int list_get_tail(List *list);

int list_get_at_index(List *list, int index);

size_t list_get_index_of(List *list, int value);


// Deletion
void list_remove_first_occurrence(List *list, int value);

void list_remove_all_occurrences(List *list, int value);

void list_remove_head(List *list);

void list_remove_tail(List *list);

void list_remove_at_index(List *list, size_t index);


// Search Function
int list_contains(List *list, int value);


// Concatenation
List *list_concatenate(const List *list1, const List *list2);


// Replacement
void list_replace_at_index(List *list, int value, int index);


// Sorting
void list_sort_ascending(List *list);

void list_sort_descending(List *list);


// Reduction
void list_get_sublist(List *list);
 */

#endif //RCUTILS_LIST_H
