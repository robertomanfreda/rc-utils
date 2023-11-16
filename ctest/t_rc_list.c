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

static bool bData1 = true;
static bool bData2 = false;

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
    list_append(list, &bData1);
    list_append(list, &bData2);

    assert(list->size == 2);
    assert(list->head != NULL);
    assert(list->head->next != NULL);
    assert(list->head->next->data == &bData2);
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

int main() {
    test_list_create();

    test_list_deep_copy();

    test_list_destroy();

    test_list_append_empty();
    test_list_append_non_empty();

    test_list_prepend_empty();
    test_list_prepend_non_empty();

    mem_check();

    printf("All list_append tests passed!\n");
    return 0;
}