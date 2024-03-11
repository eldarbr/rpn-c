#ifndef RPN_CALCULATOR_01
#define RPN_CALCULATOR_01

#include "lexunit-list.h"
#include "lexunit-stack.h"

#define _USE_MATH_DEFINES
#include <math.h>

double calculate_rpn_value(const lexunit_list_element *const rpn, const double x_value);

#endif
