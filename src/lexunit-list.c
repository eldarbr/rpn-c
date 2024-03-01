#include "lexunit-list.h"

lexunit_list_element *lexunit_list_init(char v_operator_flag, double v_operand, char v_operator) {
    lexunit_list_element *new_element = malloc(sizeof(lexunit_list_element));
    if (new_element) {
        new_element->v_operator_flag = v_operator_flag;
        if (v_operator_flag) {
            new_element->v_operator = v_operator;
        } else {
            new_element->v_operand = v_operand;
        }
        new_element->next_element = NULL;
        new_element->last_element = NULL;
    }
    return new_element;
}

lexunit_list_element *lexunit_list_add(lexunit_list_element *head, char v_operator_flag, double v_operand,
                                       char v_operator) {
    lexunit_list_element *new_element = lexunit_list_init(v_operator_flag, v_operand, v_operator);
    if (new_element) {
        if (head) {
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

lexunit_list_element *lexunit_list_add_last(lexunit_list_element *head, char v_operator_flag,
                                            double v_operand, char v_operator) {
    lexunit_list_element *new_element = lexunit_list_init(v_operator_flag, v_operand, v_operator);
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
