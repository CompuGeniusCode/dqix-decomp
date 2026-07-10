#include <globaldefs.h>

struct TaggedValue02030b44 {
    int type;
    union {
        int i;
        float f;
    } value;
};

// USA: func_02030b44
ARM float GetTaggedValueAsFloat(struct TaggedValue02030b44* v) {
    switch (v->type) {
    case 1:
        return (float)v->value.i;
    case 2:
        return v->value.f;
    }
    return 0;
}
