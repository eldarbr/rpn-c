#include "lexunit-stack.h"

lexunit_stack_element *lexunit_stack_init(const lexunit *const data) {
    lexunit_stack_element *new_element = malloc(sizeof(lexunit_stack_element));
    if (new_element) {
        new_element->next_element = NULL;
        new_element->data.v_operator_flag = data->v_operator_flag;
        if (data->v_operator_flag) {
            new_element->data.v_operator = data->v_operator;
        } else {
            new_element->data.v_operand = data->v_operand;
        }
    }
    return new_element;
}

void lexunit_stack_push(lexunit_stack_element **head, const lexunit *const data) {
    lexunit_stack_element *new_element = NULL;
    if (head && (new_element = lexunit_stack_init(data))) {
        if (!(*head)) {
            *head = new_element;
        } else {
            new_element->next_element = *head;
            *head = new_element;
        }
    }
}

lexunit lexunit_stack_pop(lexunit_stack_element **head) {
    lexunit data = {0};
    if (head && *head) {
        data = (*head)->data;
        lexunit_stack_element *tmp = (*head);
        *head = (*head)->next_element;
        free(tmp);
    }
    return data;
}

void lexunit_stack_destroy(lexunit_stack_element **head) {
    if (head) {
        while (*head) {
            lexunit_stack_element *tmp = (*head);
            *head = (*head)->next_element;
            free(tmp);
        }
    }
}

void print_lexunit_stack(const lexunit_stack_element *head) {
    char first_print = 1;
    while (head) {
        if (first_print) {
            first_print = 0;
        } else {
            printf(" ");
        }
        print_lexunit(&(head->data));
        head = head->next_element;
    }
    printf("\n");
}
