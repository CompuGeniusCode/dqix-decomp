#include <globaldefs.h>

struct State020c0278 {
    char unk0[8];
    int field8;
    int fieldC;
};

// USA: func_020c0278
ARM int CheckField8GeFieldC(struct State020c0278* state) {
    return state->field8 >= state->fieldC;
}
