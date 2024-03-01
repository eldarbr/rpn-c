#ifndef LEXUNIT_LIST_01
#define LEXUNIT_LIST_01

#include <stdio.h>
#include <stdlib.h>

struct s_lexunit_list_element {
    union {
        char v_operator;
        double v_operand;
    };
    char v_operator_flag;
    struct s_lexunit_list_element *next_element;
    struct s_lexunit_list_element *last_element;
};
typedef struct s_lexunit_list_element lexunit_list_element;

lexunit_list_element *lexunit_list_init(char v_operator_flag, char v_operator, double v_operand);
lexunit_list_element *lexunit_list_add(lexunit_list_element *head, char v_operator_flag, char v_operator,
                                       double v_operand);
lexunit_list_element *lexunit_list_add_last(lexunit_list_element *head, char v_operator_flag, char v_operator,
                                            double v_operand);
lexunit_list_element *lexunit_list_destroy(lexunit_list_element *head);

void print_lexunit_list(lexunit_list_element *head);

#endif
