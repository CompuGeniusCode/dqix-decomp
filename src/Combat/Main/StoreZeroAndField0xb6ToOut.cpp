#include <globaldefs.h>

struct Out0205a180 {
    int field0;
    int field4;
    int field8;
};

struct State0205a180 {
    char unk0[4];
    struct Out0205a180* out;
    char unk8[0xb6 - 8];
    short field_b6;
};

// USA: func_0205a180
ARM void StoreZeroAndField0xb6ToOut(struct State0205a180* state) {
    struct Out0205a180* out = state->out;
    if (out != NULL) {
        int value = state->field_b6;
        out->field4 = 0;
        out->field8 = value;
    }
}
