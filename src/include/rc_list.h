//
// Created by roberto on 11/10/23.
//

#ifndef RCUTILS_RC_LIST_H
#define RCUTILS_RC_LIST_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct NodeList NodeList;

struct NodeList {
    void *data;
    NodeList *previous;
    NodeList *next;
};

typedef enum {
    TYPE_INT,       // Represents an integer type
    TYPE_FLOAT,     // Represents a single-precision floating point type
    TYPE_DOUBLE,    // Represents a double-precision floating point type
    TYPE_CHAR,      // Represents a character type
    TYPE_BOOL,      // Represents a boolean type (true/false)
    TYPE_SHORT,     // Represents a short integer type
    TYPE_LONG,      // Represents a long integer type
    TYPE_LONGLONG,  // Represents a long long integer type
    TYPE_STRING     // Represents a string (array of characters)
} DataType;

typedef struct {
    size_t size;
    NodeList *head;
    DataType dataType;
} List;


/**
 * Allocates and initializes a new list.
 *
 * @return Pointer to the newly created list, or NULL if memory allocation fails.
 */
List *list_create(DataType dataType);

/**
 * Deep copies the given list, duplicating each element.
 *
 * @param source Pointer to the source list to be copied.
 * @return Pointer to the new list (deep copy of source), or NULL if the source is NULL or memory allocation fails
 * or NULL if the source is empty.
 */
List *list_deep_copy(const List *source);

void *list_get_element_at(const List *list, int index);

/**
 * Destroys the list, freeing memory for all nodes and the list itself.
 *
 * @param list Pointer to the list to be destroyed.
 */
void list_destroy(List *list);

/**
 * Clears and re-initializes a list, freeing all nodes and creating a new empty list.
 *
 * @param list Double pointer to the list, allowing direct modification of the caller's list pointer.
 */
void list_clear(List **list);

/**
 * Appends data to the end of the list by adding a new node.
 *
 * @param list Pointer to the list where data will be appended.
 * @param data Pointer to the data to append.
 */
void list_append(List *list, void *data);

/**
 * Prepends data to the beginning of the list by adding a new node.
 *
 * @param list Pointer to the list where data will be prepended.
 * @param data Pointer to the data to prepend.
 */
void list_prepend(List *list, void *data);

/**
 * Checks whether the list is empty (no elements).
 *
 * @param list Pointer to the list to check.
 * @return True if the list is empty, false otherwise.
 */
bool list_is_empty(const List *list);

/**
 * Checks whether the list is not empty (has elements).
 *
 * @param list Pointer to the list to check.
 * @return True if the list is not empty, false otherwise.
 */
bool list_is_not_empty(const List *list);

/**
 * Reverses the order of nodes in the list.
 *
 * @param list Pointer to the list to be reversed.
 */
void list_reverse(List *list);

/**
 * Prints the data of each node in the list in a formatted manner.
 *
 * @param list Pointer to the list to be printed.
 * @param dataType Type of data stored in the list nodes for appropriate formatting.
 */
void list_print(const List *list);

/**
 * Retrieves the number of elements in the list.
 *
 * @param list Pointer to the list.
 * @return Size of the list, or 0 if the list is NULL or empty.
 */
size_t list_get_size(const List *list);

/**
 * Retrieves the last node of the list.
 *
 * @param list Pointer to the list.
 * @return Pointer to the last node of the list, or NULL if the list is empty.
 */
static NodeList *list_get_last_node(const List *list);

/**
 * Checks if the provided list pointer is NULL.
 *
 * @param list Pointer to the list to be checked.
 * @param funcName Name of the calling function, for error messaging.
 * @return True if the list is NULL, false otherwise.
 */
static bool list_is_null_check(const List *list, const char *funcName);

/**
 * Checks if the provided list is empty.
 *
 * @param list Pointer to the list to be checked.
 * @param funcName Name of the calling function, for error messaging.
 * @return True if the list is empty, false otherwise.
 */
static bool list_is_empty_check(const List *list, const char *funcName);


#endif //RCUTILS_RC_LIST_H
