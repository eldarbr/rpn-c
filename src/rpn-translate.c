#include "rpn-translate.h"

/*
 *  Operators priority
 *  sin, cos, tan, ctg, ln, sqrt, *, /, ~
 *  +, -
 */
char get_operator_priority(char v_operator) {
    char priority = 0;
    if (v_operator == '+' || v_operator == '-') {
        priority = 1;
    } else if (strchr("*/~", v_operator)) {
        priority = 2;
    } else if (strchr("sctglq(", v_operator)) {
        priority = 3;
    }
    return priority;
}

lexunit_list_element *rpn_translate(const lexunit_list_element *source_list) {
    lexunit_list_element *translation_result = NULL;

    lexunit_stack_element *operator_stack = NULL;

    while (source_list) {
        if (!source_list->data.v_operator_flag) {
            translation_result = lexunit_list_add_last(translation_result, 0, 0, source_list->data.v_operand);
        } else if (source_list->data.v_operator == 'x') {
            translation_result = lexunit_list_add_last(translation_result, 1, 'x', 0);
        } else if (source_list->data.v_operator == ')') {
            char ended = 0;
            while (!ended) {
                char operator_from_stack = lexunit_stack_pop(&operator_stack).v_operator;
                if (operator_from_stack == '(') {
                    ended = 1;
                } else {
                    translation_result = lexunit_list_add_last(translation_result, 1, operator_from_stack, 0);
                }
            }
        } else {
            while (operator_stack && operator_stack->data.v_operator != '(' &&
                   get_operator_priority(operator_stack->data.v_operator) >
                       get_operator_priority(source_list->data.v_operator)) {
                char operator_from_stack = lexunit_stack_pop(&operator_stack).v_operator;
                translation_result = lexunit_list_add_last(translation_result, 1, operator_from_stack, 0);
            }
            lexunit_stack_push(&operator_stack, &(source_list->data));
        }
        source_list = source_list->next_element;
    }
    while (operator_stack) {
        char operator_from_stack = lexunit_stack_pop(&operator_stack).v_operator;
        translation_result = lexunit_list_add_last(translation_result, 1, operator_from_stack, 0);
    }

    return translation_result;
}
