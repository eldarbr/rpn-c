#include <stdio.h>

#include "../lexunit-list.h"

int main(void) {
    lexunit_list_element *head = NULL;

    head = lexunit_list_add(head, 1, 's', 0);
    head = lexunit_list_add(head, 0, 0, .3304);
    head = lexunit_list_add(head, 1, '-', 0);
    head = lexunit_list_add(head, 0, 0, 1000);

    print_lexunit_list(head);

    head = lexunit_list_destroy(head);

    head = lexunit_list_add_last(head, 0, 0, 120);
    head = lexunit_list_add_last(head, 0, 0, 122);
    head = lexunit_list_add_last(head, 1, '+', 0);
    head = lexunit_list_add_last(head, 0, 0, 0.99);
    head = lexunit_list_add_last(head, 1, 'q', 0);

    print_lexunit_list(head);

    head = lexunit_list_destroy(head);

    return 0;
}
