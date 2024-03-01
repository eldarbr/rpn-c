#include <stdio.h>

#include "../lexunit-parser.h"

int main(void) {
    char work_error = 0;

    char *user_input = malloc(1000);
    if (!fgets(user_input, 1000, stdin)) {
        work_error = 1;
    }

    lexunit_list_element *head = NULL;
    if (!work_error) {
        head = lexunits_parse_expression(user_input);
    }
    if (!head) {
        work_error = 1;
    }
    if (!work_error) {
        print_lexunit_list(head);
        replace_unary_minuses(head);
        print_lexunit_list(head);
        char valid = validate_lexunit_list(head);
        if (valid) {
            printf("valid\n");
        } else {
            printf("invalid\n");
        }
    }

    if (work_error) {
        printf("n/a\n");
    }
    if (head) {
        head = lexunit_list_destroy(head);
    }
    if (user_input) {
        free(user_input);
    }
    return work_error;
}
