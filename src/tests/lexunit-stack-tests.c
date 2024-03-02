#include "../lexunit-stack.h"

int main(void) {
    lexunit_stack_element *head = NULL;
    {
        lexunit tmp_lexunit = {0};
        lexunit_stack_push(&head, &tmp_lexunit);
    }
    {
        lexunit tmp_lexunit;
        tmp_lexunit.v_operator_flag = 1;
        tmp_lexunit.v_operator = 'c';
        lexunit_stack_push(&head, &tmp_lexunit);
    }
    {
        lexunit tmp_lexunit;
        tmp_lexunit.v_operator_flag = 0;
        tmp_lexunit.v_operand = 5432;
        lexunit_stack_push(&head, &tmp_lexunit);
    }
    {
        lexunit tmp_lexunit = {0};
        lexunit_stack_push(&head, &tmp_lexunit);
    }
    {
        lexunit tmp_lexunit;
        tmp_lexunit.v_operator_flag = 1;
        tmp_lexunit.v_operator = 'c';
        lexunit_stack_push(&head, &tmp_lexunit);
    }
    {
        lexunit tmp_lexunit;
        tmp_lexunit.v_operator_flag = 0;
        tmp_lexunit.v_operand = 5432;
        lexunit_stack_push(&head, &tmp_lexunit);
    }
    {
        lexunit tmp_lexunit = {0};
        lexunit_stack_push(&head, &tmp_lexunit);
    }
    {
        lexunit tmp_lexunit;
        tmp_lexunit.v_operator_flag = 1;
        tmp_lexunit.v_operator = 'c';
        lexunit_stack_push(&head, &tmp_lexunit);
    }
    {
        lexunit tmp_lexunit;
        tmp_lexunit.v_operator_flag = 0;
        tmp_lexunit.v_operand = 5432;
        lexunit_stack_push(&head, &tmp_lexunit);
    }

    print_lexunit_stack(head);

    while (head) {
        lexunit tmp_lexunit = lexunit_stack_pop(&head);
        print_lexunit(&tmp_lexunit);
        printf("\n");
    }

    lexunit_stack_destroy(&head);
}
