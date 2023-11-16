//
// Created by roberto on 11/15/23.
//

#include <assert.h>
#include <stdio.h>
#include "rc_list.h"
#include "t_utils.h"

static long long llData1 = 10;
static long long llData2 = 20;
static long long llData3 = 30;
static long long llData4 = 40;
static long long llData5 = 50;

static long lData1 = 10;
static long lData2 = 20;
static long lData3 = 30;
static long lData4 = 40;
static long lData5 = 50;

static float fData1 = 3.14f;
static float fData2 = 3.15f;
static float fData3 = 3.16f;
static float fData4 = 3.17f;
static float fData5 = 3.18f;

static bool bDataTrue = true;
static bool bDataFalse = false;

static const char *sData1 = "sData1";
static const char *sData2 = "sData2";
static const char *sData3 = "sData3";
static const char *sData4 = "sData4";
static const char *sData5 = "sData5";

static char cData1 = 'a';
static char cData2 = 'b';
static char cData3 = 'c';
static char cData4 = 'd';
static char cData5 = 'e';

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
    list_append(list, &llData1);
    list_append(list, &llData2);

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
    list_append(list, &fData2);
    list_append(list, &fData3);
    list_append(list, &fData4);
    list_append(list, &fData5);
    list_prepend(list, &fData1);

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
    list_append(list, &fData1);

    assert(list_get_element_at(list, 0) == &fData1);
    assert(list_get_element_at(list, 1) == NULL);

    list_print(list);

    list_destroy(list);

    mem_check();
}

void test_list_destroy() {
    printf("Executing: %s\n", __func__);

    List *list = list_create(TYPE_STRING);
    list_append(list, (char *) sData1);
    list_append(list, (char *) sData2);
    list_append(list, (char *) sData3);
    list_append(list, (char *) sData4);
    list_append(list, (char *) sData5);

    list_print(list);

    list_destroy(list);

    mem_check();
}

void test_list_append_empty() {
    printf("Executing: %s\n", __func__);

    List *list = list_create(TYPE_CHAR);

    list_append(list, &cData1);

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
    list_append(list, &bDataTrue);
    list_append(list, &bDataFalse);

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
    list_prepend(list, &llData1);

    assert(list->size == 0);
    assert(list->head == NULL);

    list_print(list);

    list_destroy(list);

    mem_check();
}

void test_list_prepend_non_empty() {
    printf("Executing: %s\n", __func__);

    List *list = list_create(TYPE_LONGLONG);
    list_append(list, &llData1);
    list_prepend(list, &llData2);

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
    list_append(list, &fData1);
    list_append(list, &fData2);
    list_append(list, &fData3);
    list_append(list, &fData4);

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

    list_append(list, &lData1);
    list_prepend(list, &lData2);

    assert(list_is_empty(list) == false);

    list_print(list);

    list_destroy(list);

    mem_check();
}

void t_list_is_not_empty() {
    printf("Executing: %s\n", __func__);

    List *list = list_create(TYPE_LONG);

    assert(list_is_not_empty(list) == false);

    list_append(list, &lData1);
    list_prepend(list, &lData2);

    assert(list_is_not_empty(list) == true);

    list_print(list);

    list_destroy(list);

    mem_check();
}

void t_list_get_size() {
    printf("Executing: %s\n", __func__);

    List *list = list_create(TYPE_INT);

    for (int i = 0; i < 10; ++i) {
        list_append(list, &i);
    }

    assert(list->size == 10);

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

    test_list_destroy();

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