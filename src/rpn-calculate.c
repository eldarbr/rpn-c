#include "rpn-calculate.h"

/*
 *  binary:
 *  + - * /
 *  unary:
 *  ~ s c t g q l
 */
void apply_operator(lexunit_stack_element *calc_stack, const lexunit *const operator_lexunit) {
    lexunit first_operand = lexunit_stack_pop(&calc_stack);
    lexunit second_operand = {{0}, 0};
    lexunit calculation_result = {{0}, 0};
    if (operator_lexunit->v_operator == '+' || operator_lexunit->v_operator == '-' ||
        operator_lexunit->v_operator == '*' || operator_lexunit->v_operator == '/') {
        second_operand = lexunit_stack_pop(&calc_stack);
    }
    char the_operator = operator_lexunit->v_operator;
    if (the_operator == '+') {
        calculation_result.v_operand = first_operand.v_operand + second_operand.v_operand;
    } else if (the_operator == '-') {
        calculation_result.v_operand = first_operand.v_operand - second_operand.v_operand;
    } else if (the_operator == '*') {
        calculation_result.v_operand = first_operand.v_operand * second_operand.v_operand;
    } else if (the_operator == '/') {
        calculation_result.v_operand = first_operand.v_operand / second_operand.v_operand;
    } else if (the_operator == 's') {
        calculation_result.v_operand = sin(first_operand.v_operand);
    } else if (the_operator == 'c') {
        calculation_result.v_operand = cos(first_operand.v_operand);
    } else if (the_operator == 't') {
        calculation_result.v_operand = tan(first_operand.v_operand);
    } else if (the_operator == 'g') {
        calculation_result.v_operand = tan(M_PI / 2 - first_operand.v_operand);
    } else if (the_operator == 'q') {
        calculation_result.v_operand = sqrt(first_operand.v_operand);
    } else if (the_operator == 'l') {
        calculation_result.v_operand = log(first_operand.v_operand);
    } else if (the_operator == '~') {
        calculation_result.v_operand = -first_operand.v_operand;
    }
    lexunit_stack_push(&calc_stack, &calculation_result);
}

double calculate_rpn_value(const lexunit_list_element *const rpn, const double x_value) {
    lexunit_stack_element *calc_stack = NULL;

    const lexunit_list_element *current_rpn_element = rpn;
    while (current_rpn_element) {
        lexunit current_lexunit = current_rpn_element->data;
        if (current_lexunit.v_operator_flag && current_lexunit.v_operator == 'x') {
            current_lexunit.v_operator_flag = 0;
            current_lexunit.v_operand = x_value;
        }
        if (current_lexunit.v_operator_flag) {
            apply_operator(calc_stack, &current_lexunit);
        } else {
            lexunit_stack_push(&calc_stack, &current_lexunit);
        }
        current_rpn_element = current_rpn_element->next_element;
    }

    double result = lexunit_stack_pop(&calc_stack).v_operand;
    // safety measure - should yet be empty here
    lexunit_stack_destroy(&calc_stack);
    return result;
}
