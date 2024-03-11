#ifndef RPN_CALCULATOR_01
#define RPN_CALCULATOR_01

#include "lexunit-list.h"
#include "lexunit-stack.h"

#define _USE_MATH_DEFINES
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

double calculate_rpn_value(const lexunit_list_element *const rpn, const double x_value);

#endif
