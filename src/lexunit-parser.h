#ifndef LEXUNIT_PARSER_01
#define LEXUNIT_PARSER_01

#include <stdio.h>
#include <string.h>

#include "lexunit-list.h"

lexunit_list_element *lexunits_parse_expression(char *expression);

void replace_unary_minuses(lexunit_list_element *head);

char validate_lexunit_list(lexunit_list_element *head);

#endif
