#include <globaldefs.h>

struct S_a0948 {
    short* keys;
    signed char* values;
    short count;
};

// USA: func_020a0948
ARM void ClearKeyValueList020a0948(struct S_a0948* p) {
    p->keys = NULL;
    p->values = NULL;
    p->count = 0;
}
