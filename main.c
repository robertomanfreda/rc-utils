#include "src/include/list.h"
#include "src/include/memory_wrapper.h"

int main() {
    List *list = list_create();

    list_prepend(list, 8);
    list_append(list, 10);
    list_append(list, 11);
    list_prepend(list, 9);

    list_print(list);

    list_clear(&list);
    printf("List is empty - true: %s\n", list_is_empty(list) ? "true" : "false");
    list_print(list);

    list_append(list, 1);
    list_print(list);

    printf("List is empty - false: %s\n", list_is_empty(list) ? "true" : "false");
    printf("List is not empty - true: %s\n", list_is_not_empty(list) ? "true" : "false");

    list_clear(&list);

    list_append(list, 1);
    list_append(list, 2);
    list_append(list, 3);
    list_prepend(list, 1);

    printf("---\n");
    list_print(list);

    List *listCopy = list_deep_copy(list);
    list_print(listCopy);

    list_reverse(listCopy);

    printf("list size is: %zu\n\n", list_get_size(listCopy));
    list_print(listCopy);
    list_destroy(list);
    list_destroy(listCopy);

    rc_print_memory_usage("END");
    return 0;
}
