#include <globaldefs.h>

struct State_1f9b8 {
    int field0;
    int field4;
    int field8;
    int fieldC;
    int field10;
    unsigned char field14;
    char pad15[0x3];
    int field18;
    unsigned char field1C;
    unsigned char field1D;
};

// USA: func_0201f9b8
ARM void InitStruct_0201f9b8(struct State_1f9b8* state) {
    state->field0 = -1;
    state->field4 = -1;
    state->field8 = -1;
    state->fieldC = -1;
    state->field10 = 0;
    state->field14 = 0;
    state->field18 = 0;
    state->field1C = 0;
    state->field1D = 0;
}
