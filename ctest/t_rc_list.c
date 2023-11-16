//
// Created by roberto on 11/15/23.
//

#include <assert.h>
#include <stdio.h>
#include "rc_list.h"
#include "t_utils.h"
#include "rc_memory.h"

void test_list_create() {
    printf("Executing: %s\n", __func__);

    List *list = list_create(TYPE_LONGLONG);

    assert(list != NULL);
    assert(list->size == 0);
    assert(list->head == NULL);

    list_print(list);

    list_destroy(list);

    mem_check();
}

void test_list_deep_copy() {
    printf("Executing: %s\n", __func__);

    List *list = list_create(TYPE_LONGLONG);
    list_append(list, &llData1, false);
    list_append(list, &llData2, false);

    assert(list != NULL);
    assert(list->size == 2);
    assert(list->head->data == &llData1);
    assert(list->head->next->data == &llData2);

    List *listCopy = list_deep_copy(list);
    assert(listCopy != NULL);
    assert(listCopy->size == 2);
    assert(listCopy->head->data == &llData1);
    assert(listCopy->head->next->data == &llData2);

    list_print(list);
    list_print(listCopy);

    list_destroy(list);
    list_destroy(listCopy);

    mem_check();
}

void t_list_get_element_at() {
    printf("Executing: %s\n", __func__);

    List *list = list_create(TYPE_FLOAT);
    list_append(list, &fData2, false);
    list_append(list, &fData3, false);
    list_append(list, &fData4, false);
    list_append(list, &fData5, false);
    list_prepend(list, &fData1, false);

    assert(list_get_element_at(list, 0) == &fData1);
    assert(list_get_element_at(list, 1) == &fData2);
    assert(list_get_element_at(list, 2) == &fData3);
    assert(list_get_element_at(list, 3) == &fData4);
    assert(list_get_element_at(list, 4) == &fData5);

    list_print(list);

    list_destroy(list);

    mem_check();
}

void t_list_get_element_at_index_out_of_bounds() {
    printf("Executing: %s\n", __func__);

    List *list = list_create(TYPE_FLOAT);
    list_append(list, &fData1, false);

    assert(list_get_element_at(list, 0) == &fData1);
    assert(list_get_element_at(list, 1) == NULL);

    list_print(list);

    list_destroy(list);

    mem_check();
}

void test_list_get_first_element() {
    printf("Executing: %s\n", __func__);

    List *list = list_create(TYPE_FLOAT);

    list_append(list, &fData1, false);
    assert(list_get_first_element(list) == &fData1);
    list_print(list);

    list_append(list, &fData2, false);
    assert(list_get_first_element(list) == &fData1);
    list_print(list);

    list_prepend(list, &fData3, false);
    assert(list_get_first_element(list) == &fData3);
    list_print(list);

    list_destroy(list);

    mem_check();
}

void test_list_get_last_element() {
    printf("Executing: %s\n", __func__);

    List *list = list_create(TYPE_FLOAT);

    list_append(list, &fData1, false);
    assert(list_get_last_element(list) == &fData1);
    list_print(list);

    list_append(list, &fData2, false);
    assert(list_get_last_element(list) == &fData2);
    list_print(list);

    list_destroy(list);

    mem_check();
}

void test_list_destroy() {
    printf("Executing: %s\n", __func__);

    List *list = list_create(TYPE_STRING);
    list_append(list, (char *) sData1, false);
    list_append(list, (char *) sData2, false);
    list_append(list, (char *) sData3, false);
    list_append(list, (char *) sData4, false);
    list_append(list, (char *) sData5, false);

    list_print(list);

    list_destroy(list);

    mem_check();
}

void test_list_clear() {
    printf("Executing: %s\n", __func__);

    List *list = list_create(TYPE_STRING);
    list_append(list, (char *) sData1, false);
    list_append(list, (char *) sData2, false);
    list_print(list);

    list_clear(&list);
    list_print(list);

    assert(list_is_empty(list) == true);

    list_destroy(list);

    mem_check();
}

void test_list_append_empty() {
    printf("Executing: %s\n", __func__);

    List *list = list_create(TYPE_CHAR);

    list_append(list, &cData1, false);

    assert(list->size == 1);
    assert(list->head != NULL);
    assert(list->head->data == &cData1);
    assert(list->head->next == NULL);
    assert(list->head->previous == NULL);

    list_print(list);

    list_destroy(list);

    mem_check();
}

void test_list_append_non_empty() {
    printf("Executing: %s\n", __func__);

    List *list = list_create(TYPE_BOOL);
    list_append(list, &bDataTrue, false);
    list_append(list, &bDataFalse, false);

    assert(list->size == 2);
    assert(list->head != NULL);
    assert(list->head->next != NULL);
    assert(list->head->next->data == &bDataFalse);
    assert(list->head->next->previous == list->head);

    list_print(list);

    list_destroy(list);

    mem_check();
}

void test_list_prepend_empty() {
    printf("Executing: %s\n", __func__);

    List *list = list_create(TYPE_LONGLONG);
    list_prepend(list, &llData1, false);

    assert(list->size == 0);
    assert(list->head == NULL);

    list_print(list);

    list_destroy(list);

    mem_check();
}

void test_list_prepend_non_empty() {
    printf("Executing: %s\n", __func__);

    List *list = list_create(TYPE_LONGLONG);
    list_append(list, &llData1, false);
    list_prepend(list, &llData2, false);

    assert(list->size == 2);
    assert(list->head != NULL);
    assert(list->head->next != NULL);
    assert(list->head->data == &llData2);
    assert(list->head->next->data == &llData1);
    assert(list->head->next->previous == list->head);

    list_print(list);

    list_destroy(list);

    mem_check();
}

void t_list_reverse() {
    printf("Executing: %s\n", __func__);

    List *list = list_create(TYPE_FLOAT);
    list_append(list, &fData1, false);
    list_append(list, &fData2, false);
    list_append(list, &fData3, false);
    list_append(list, &fData4, false);

    assert(list_get_element_at(list, 0) == &fData1);
    assert(list_get_element_at(list, 1) == &fData2);
    assert(list_get_element_at(list, 2) == &fData3);
    assert(list_get_element_at(list, 3) == &fData4);
    list_print(list);

    list_reverse(list);
    list_print(list);

    assert(list_get_element_at(list, 0) == &fData4);
    assert(list_get_element_at(list, 1) == &fData3);
    assert(list_get_element_at(list, 2) == &fData2);
    assert(list_get_element_at(list, 3) == &fData1);

    list_destroy(list);

    mem_check();
}

void t_list_is_empty() {
    printf("Executing: %s\n", __func__);

    List *list = list_create(TYPE_LONG);

    assert(list_is_empty(list) == true);

    list_append(list, &lData1, false);
    list_prepend(list, &lData2, false);

    assert(list_is_empty(list) == false);

    list_print(list);

    list_destroy(list);

    mem_check();
}

void t_list_is_not_empty() {
    printf("Executing: %s\n", __func__);

    List *list = list_create(TYPE_LONG);

    assert(list_is_not_empty(list) == false);

    list_append(list, &lData1, false);
    list_prepend(list, &lData2, false);

    assert(list_is_not_empty(list) == true);

    list_print(list);

    list_destroy(list);

    mem_check();
}

void t_list_get_size() {
    printf("Executing: %s\n", __func__);

    List *list = list_create(TYPE_INT);

    for (int i = 0; i < 10; ++i) {
        int *value = memory_malloc(sizeof(int));

        if (value == NULL) {
            // Handle memory allocation failure
            exit(1);
        }
        *value = i;
        list_append(list, value, true);
    }


    assert(list_get_size(list) == 10);

    list_print(list);

    list_destroy(list);

    mem_check();
}

int main() {
    printf("Executing tests from file: %s\n\n", __FILE_NAME__);

    test_list_create();

    test_list_deep_copy();

    t_list_get_element_at();
    t_list_get_element_at_index_out_of_bounds();

    test_list_get_first_element();
    test_list_get_last_element();

    test_list_destroy();

    test_list_clear();

    test_list_append_empty();
    test_list_append_non_empty();

    test_list_prepend_empty();
    test_list_prepend_non_empty();

    t_list_reverse();

    t_list_is_empty();
    t_list_is_not_empty();

    t_list_get_size();

    mem_check();

    printf("All list_append tests passed!\n");
    return 0;
}