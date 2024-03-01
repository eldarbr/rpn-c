#include <stdio.h>

#include "../lexunit-list.h"

void print_lexunit_list(lexunit_list_element *head);

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

void print_lexunit_list(lexunit_list_element *head) {
    char first_element = 1;
    while (head) {
        if (first_element) {
            first_element = 0;
        } else {
            printf(" ");
        }
        if (head->v_operator_flag) {
            printf("%c", head->v_operator);
        } else {
            printf("%lf", head->v_operand);
        }
        head = head->next_element;
    }
    printf("\n");
}
