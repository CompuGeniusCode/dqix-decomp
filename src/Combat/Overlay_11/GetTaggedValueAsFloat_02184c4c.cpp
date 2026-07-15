#include <globaldefs.h>

struct TaggedNumber02184c4c {
    int type;
    union {
        int i;
        float f;
    } value;
};

// USA: func_ov011_02184c4c
ARM float GetTaggedValueAsFloat_02184c4c(struct TaggedNumber02184c4c* v) {
    if (v->type == 0) return (float)v->value.i;
    return v->value.f;
}
