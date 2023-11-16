//
// Created by roberto on 11/15/23.
//

#include <assert.h>
#include <stdio.h>
#include "rc_list.h"
#include "t_utils.h"

static long long data1 = 10;
static long long data2 = 20;
static long long data3 = 30;
static long long data4 = 40;
static long long data5 = 50;

void test_list_create() {
    printf("Executing: %s\n", __func__);

    List *list = list_create();

    assert(list != NULL);
    assert(list->size == 0);
    assert(list->head == NULL);

    list_destroy(list);

    mem_check();
}

void test_list_deep_copy() {
    printf("Executing: %s\n", __func__);

    List *list = list_create();
    list_append(list, &data1);
    list_append(list, &data2);

    assert(list != NULL);
    assert(list->size == 2);
    assert(list->head->data == &data1);
    assert(list->head->next->data == &data2);

    List *listCopy = list_deep_copy(list);
    assert(listCopy != NULL);
    assert(listCopy->size == 2);
    assert(listCopy->head->data == &data1);
    assert(listCopy->head->next->data == &data2);

    list_destroy(list);
    list_destroy(listCopy);

    mem_check();
}

void test_list_append_empty() {
    printf("Executing: %s\n", __func__);

    List *list = list_create();
    long long data = 42;
    list_append(list, &data);

    assert(list->size == 1);
    assert(list->head != NULL);
    assert(list->head->data == &data);
    assert(list->head->next == NULL);
    assert(list->head->previous == NULL);

    list_destroy(list);

    mem_check();
}

void test_list_append_non_empty() {
    printf("Executing: %s\n", __func__);

    List *list = list_create();
    list_append(list, &data1);
    list_append(list, &data2);

    assert(list->size == 2);
    assert(list->head != NULL);
    assert(list->head->next != NULL);
    assert(list->head->next->data == &data2);
    assert(list->head->next->previous == list->head);

    list_destroy(list);

    mem_check();
}

void test_list_prepend_empty() {
    printf("Executing: %s\n", __func__);

    List *list = list_create();
    list_prepend(list, &data1);

    assert(list->size == 0);
    assert(list->head == NULL);

    list_destroy(list);

    mem_check();
}

void test_list_prepend_non_empty() {
    printf("Executing: %s\n", __func__);

    List *list = list_create();
    list_append(list, &data1);
    list_prepend(list, &data2);

    assert(list->size == 2);
    assert(list->head != NULL);
    assert(list->head->next != NULL);
    assert(list->head->data == &data2);
    assert(list->head->next->data == &data1);
    assert(list->head->next->previous == list->head);

    list_destroy(list);

    mem_check();
}

int main() {
    test_list_create();

    test_list_deep_copy();

    test_list_append_empty();
    test_list_append_non_empty();

    test_list_prepend_empty();
    test_list_prepend_non_empty();

    mem_check();

    printf("All list_append tests passed!\n");
    return 0;
}