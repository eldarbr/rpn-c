#ifndef LEXUNIT_STACK_01
#define LEXUNIT_STACK_01

#include <stdio.h>
#include <stdlib.h>

#include "lexunit.h"

struct s_lexunit_stack_element {
    lexunit data;
    struct s_lexunit_stack_element *next_element;
};
typedef struct s_lexunit_stack_element lexunit_stack_element;

lexunit_stack_element *lexunit_stack_init(const lexunit *const data);
void lexunit_stack_push(lexunit_stack_element **head, const lexunit *const data);
lexunit lexunit_stack_pop(lexunit_stack_element **head);
void lexunit_stack_destroy(lexunit_stack_element **head);

void print_lexunit_stack(const lexunit_stack_element *head);

#endif
