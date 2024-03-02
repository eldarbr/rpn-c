#ifndef LEXUNIT_STRUCT_01
#define LEXUNIT_STRUCT_01

struct s_lexunit {
    union {
        char v_operator;
        double v_operand;
    };
    char v_operator_flag;
};
typedef struct s_lexunit lexunit;

#endif
