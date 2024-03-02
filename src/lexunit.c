#include "lexunit.h"

void print_lexunit(const lexunit *const data) {
    if (data->v_operator_flag) {
        printf("%c", data->v_operator);
    } else {
        printf("%lf", data->v_operand);
    }
}
