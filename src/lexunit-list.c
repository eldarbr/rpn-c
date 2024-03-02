#include "lexunit-list.h"

lexunit_list_element *lexunit_list_init(char v_operator_flag, char v_operator, double v_operand) {
    lexunit_list_element *new_element = malloc(sizeof(lexunit_list_element));
    if (new_element) {
        new_element->data.v_operator_flag = v_operator_flag;
        if (v_operator_flag) {
            new_element->data.v_operator = v_operator;
        } else {
            new_element->data.v_operand = v_operand;
        }
        new_element->next_element = NULL;
        new_element->last_element = NULL;
    }
    return new_element;
}

lexunit_list_element *lexunit_list_add(lexunit_list_element *head, char v_operator_flag, char v_operator,
                                       double v_operand) {
    lexunit_list_element *new_element = lexunit_list_init(v_operator_flag, v_operator, v_operand);
    if (new_element) {
        if (head) {
            new_element->next_element = head->next_element;
            head->next_element = new_element;
            if (!head->last_element) {
                head->last_element = new_element;
            }
        } else {
            head = new_element;
        }
    }
    return head;
}

lexunit_list_element *lexunit_list_add_last(lexunit_list_element *head, char v_operator_flag, char v_operator,
                                            double v_operand) {
    lexunit_list_element *new_element = lexunit_list_init(v_operator_flag, v_operator, v_operand);
    if (new_element) {
        if (head) {
            if (head->last_element) {
                head->last_element->next_element = new_element;
                head->last_element = new_element;
            } else {
                head->next_element = new_element;
                head->last_element = new_element;
            }
        } else {
            head = new_element;
        }
    }
    return head;
}

lexunit_list_element *lexunit_list_destroy(lexunit_list_element *head) {
    while (head) {
        lexunit_list_element *tmp = head;
        head = head->next_element;
        free(tmp);
    }
    return head;
}

void print_lexunit_list(lexunit_list_element *head) {
    char first_element = 1;
    while (head) {
        if (first_element) {
            first_element = 0;
        } else {
            printf(" ");
        }
        if (head->data.v_operator_flag) {
            printf("%c", head->data.v_operator);
        } else {
            printf("%lf", head->data.v_operand);
        }
        head = head->next_element;
    }
    printf("\n");
}
