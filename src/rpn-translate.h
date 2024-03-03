#ifndef RPN_TRANSLATOR_01
#define RPN_TRANSLATOR_01

#include <string.h>

#include "lexunit-list.h"
#include "lexunit-stack.h"

lexunit_list_element *rpn_translate(const lexunit_list_element *source_list);

#endif
