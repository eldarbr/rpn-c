#include "lexunit-parser.h"

char get_operator(char *expression, int *operator_size) {
    char v_operator = 0;
    int expression_length = 0;
    if (expression) {
        expression_length = strlen(expression);
    }
    if (expression_length &&
        (*expression == '+' || *expression == '-' || *expression == '~' || *expression == '*' ||
         *expression == '/' || *expression == '(' || *expression == ')' || *expression == 'x')) {
        v_operator = *expression;
        *operator_size = 1;
    } else if (expression_length >= 4 && expression[0] == 's' && expression[1] == 'q' &&
               expression[2] == 'r' && expression[3] == 't') {
        v_operator = 'q';
        *operator_size = 4;
    } else if (expression_length >= 3 && expression[0] == 's' && expression[1] == 'i' &&
               expression[2] == 'n') {
        v_operator = 's';
        *operator_size = 3;
    } else if (expression_length >= 3 && expression[0] == 'c' && expression[1] == 'o' &&
               expression[2] == 's') {
        v_operator = 'c';
        *operator_size = 3;
    } else if (expression_length >= 3 && expression[0] == 't' && expression[1] == 'a' &&
               expression[2] == 'n') {
        v_operator = 't';
        *operator_size = 3;
    } else if (expression_length >= 3 && expression[0] == 'c' && expression[1] == 't' &&
               expression[2] == 'g') {
        v_operator = 'g';
        *operator_size = 3;
    } else if (expression_length >= 2 && expression[0] == 'l' && expression[1] == 'n') {
        v_operator = 'l';
        *operator_size = 2;
    }
    return v_operator;
}

lexunit_list_element *lexunits_parse_expression(char *expression) {
    char work_error = 0;
    lexunit_list_element *head = NULL;

    if (!expression) {
        work_error = 1;
    }

    while (!work_error && *expression) {
        double current_operand = 0;
        int chars_to_skip = 0;
        char current_operator = 0;
        if (*expression == ' ' || *expression == '\n') {
            chars_to_skip = 1;
        } else if ((current_operator = get_operator(expression, &chars_to_skip))) {
            head = lexunit_list_add_last(head, 1, current_operator, 0);
        } else if (!sscanf(expression, "%lf%n", &current_operand, &chars_to_skip)) {
            work_error = 1;
        } else {
            head = lexunit_list_add_last(head, 0, 0, current_operand);
        }
        expression += chars_to_skip;
    }

    if (work_error) {
        head = lexunit_list_destroy(head);
    }
    return head;
}

/*
 *  +
 *  -
 *  ~
 *  *
 *  /
 *  (
 *  )
 *  sin
 *  cos
 *  tan
 *  ctg
 *  sqrt
 *  ln
 *  x
 *
 *  d = digit
 *  n = none
 */
char is_a_valid_sequence(char previous, char current) {
    char valid = 0;
    if ((current == 'd' || current == 'x') && strchr("n+-~*/(", previous)) {
        valid = 1;
    } else if (strchr("+-*/", current) && strchr("dx)", previous)) {
        valid = 1;
    } else if (strchr("sctgql", current) && strchr("n+-*/~(", previous)) {
        valid = 1;
    } else if (current == ')' && strchr("dx", previous)) {
        valid = 1;
    } else if (current == '(' && strchr("sctglq+-~*/(n", previous)) {
        valid = 1;
    } else if (current == '~' && strchr("n+-*/(", previous)) {
        valid = 1;
    }
    return valid;
}

char validate_lexunit_list(lexunit_list_element *head) {
    char valid_list = 1;

    int parenthesis_counter = 0;
    char previous_element = 'n';

    while (valid_list && head) {
        char current_element = 0;
        if (head->data.v_operator_flag) {
            current_element = head->data.v_operator;
            if (current_element == '(') {
                ++parenthesis_counter;
            } else if (current_element == ')') {
                --parenthesis_counter;
            }
        } else {
            current_element = 'd';
        }
        if (parenthesis_counter < 0) {
            valid_list = 0;
        }
        if (valid_list && !is_a_valid_sequence(previous_element, current_element)) {
            valid_list = 0;
        } else if (valid_list) {
            previous_element = current_element;
            head = head->next_element;
        }
    }

    return valid_list;
}

void replace_unary_minuses(lexunit_list_element *head) {
    if (head && head->data.v_operator_flag && head->data.v_operator == '-') {
        head->data.v_operator = '~';
    }
    while (head && head->next_element) {
        if (head->data.v_operator_flag && !strchr("x)", head->data.v_operator) &&
            head->next_element->data.v_operator_flag && head->next_element->data.v_operator == '-') {
            head->next_element->data.v_operator = '~';
        }
        head = head->next_element;
    }
}
