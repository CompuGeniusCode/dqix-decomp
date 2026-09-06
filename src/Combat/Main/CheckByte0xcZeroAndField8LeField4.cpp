#include <globaldefs.h>

struct State02059a2c {
    char unk0[4];
    unsigned int field4;
    unsigned int field8;
    unsigned char flagC;
};

// USA: func_02059a2c
ARM int CheckByte0xcZeroAndField8LeField4(struct State02059a2c* state) {
    if (state->flagC != 0) return 0;
    return state->field8 <= state->field4;
}
