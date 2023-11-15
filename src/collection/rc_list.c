//
// Created by roberto on 11/10/23.
//

#include <stdio.h>
#include "../include/rc_list.h"
#include "../include/rc_memory.h"

List *list_create() {
    List *list = memory_malloc(sizeof(List));

    if (list == NULL) {
        fprintf(stderr, "ERROR - %s: Unable to allocate memory.\n", __func__);
        exit(1); // Exit if allocation failed
    }

    list->size = 0;
    list->head = NULL;

    return list;
}

List *list_deep_copy(const List *source) {
    if (source == NULL) {
        fprintf(stderr, "WARN - %s: The source list is NULL.\n", __func__);
        return NULL; // Return NULL if the source list is NULL
    }

    // Create a new list
    List *copy = list_create();
    if (copy == NULL) {
        fprintf(stderr, "ERROR - %s: Unable to allocate memory for list.\n", __func__);
        exit(1); // Return NULL if memory allocation for the new list fails
    }

    // Iterate through the source list and copy each node
    NodeList *current = source->head;
    while (current != NULL) {
        // Append the data of the current node of the source list to the new list
        list_append(copy, current->data);
        current = current->next;
    }

    return copy;
}

void list_destroy(List *list) {
    // Return immediately if the list is NULL
    if (list == NULL) {
        return;
    }

    // Iterate through the list and free each node
    NodeList *current = list->head;
    while (current != NULL) {
        NodeList *temp = current;
        current = current->next;
        memory_free(temp, sizeof(NodeList)); // Free the node
    }

    // Free the list structure itself
    memory_free(list, sizeof(List));
}

void list_clear(List **list) {
    if (list == NULL || *list == NULL) {
        return; // Safety check
    }

    list_destroy(*list);    // Free the entire list
    *list = list_create();  // Re-create the list and update the original pointer
}

void list_append(List *list, int data) {
    NodeList *node = (NodeList *) memory_malloc(sizeof(NodeList));

    if (node == NULL) {
        fprintf(stderr, "ERROR - %s: Unable to allocate memory for node.\n", __func__);
        exit(1);
    }

    node->data = data;
    node->next = NULL;

    // If the list is empty, make the new node the head
    if (list->head == NULL) {
        node->previous = NULL;
        list->head = node;
    } else {
        // Otherwise, find the end of the list and append the node
        NodeList *last = list_get_last_node(list);
        last->next = node;
        node->previous = last;
    }

    // Increase the list's size
    list->size++;
}

void list_prepend(List *list, int data) {
    NodeList *node = (NodeList *) memory_malloc(sizeof(NodeList));

    if (node == NULL) {
        fprintf(stderr, "ERROR - %s: Unable to allocate memory for node.\n", __func__);
        exit(1);
    }

    // Set the node's data and previous pointer
    node->data = data;
    node->previous = NULL;

    // Set the new node's next pointer to the current head and update the head
    node->next = list->head;

    // If the list isn't empty, update the previous head's previous pointer
    if (list->head != NULL) {
        list->head->previous = node;
    }
    list->head = node;

    // Increase the list's size
    list->size++;
}

bool list_is_empty(const List *list) {
    if (list == NULL) {
        fprintf(stderr, "WARN - %s: The list is NULL.\n", __func__);
        return NULL;
    }

    return list->head == NULL
           ? true
           : false;
}

bool list_is_not_empty(const List *list) {
    if (list == NULL) {
        fprintf(stderr, "WARN - %s: The list is NULL.\n", __func__);
        return NULL;
    }

    return list->head != NULL
           ? true
           : false;
}

void list_reverse(List *list) {
    if (list == NULL) {
        fprintf(stderr, "WARN - %s: The list is NULL.\n", __func__);
        return;
    } else if (list_is_empty(list)) {
        fprintf(stderr, "WARN - %s: The list is EMPTY.\n", __func__);
        return;
    }

    NodeList *current = list->head;
    NodeList *prev = NULL;
    NodeList *next = NULL;

    while (current != NULL) {
        // Swap the next and previous pointers of the current node
        next = current->next;
        current->next = prev;
        current->previous = next;

        // Move to the next node in the original list
        prev = current;
        current = next;
    }

    // Update the head of the list
    list->head = prev;
}

void list_print(const List *list) {
    // Check if the list is NULL and return if so
    if (list == NULL) {
        fprintf(stderr, "WARN - %s: The list is NULL.\n", __func__);
        return;
    }

    // Iterate through the list and print each node's data
    NodeList *current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    // Print a newline for formatting
    printf("\n");
}

size_t list_get_size(const List *list) {
    if (list == NULL) {
        fprintf(stderr, "WARN - %s: The list is NULL.\n", __func__);
        return 0; // Return NULL if the list is NULL
    } else if (list_is_empty(list)) {
        fprintf(stderr, "WARN - %s: The list is EMPTY.\n", __func__);
        return 0; // Return NULL if the list is empty
    }

    return list->size;
}

static NodeList *list_get_last_node(const List *list) {
    if (list == NULL) {
        fprintf(stderr, "WARN - %s: The list is NULL.\n", __func__);
        return NULL; // Return NULL if the list is NULL
    } else if (list_is_empty(list)) {
        fprintf(stderr, "WARN - %s: The list is EMPTY.\n", __func__);
        return NULL; // Return NULL if the list is empty
    }

    NodeList *current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }

    return current; // Return the last node
}