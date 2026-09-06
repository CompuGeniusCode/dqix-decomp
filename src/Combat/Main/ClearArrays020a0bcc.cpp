#include <globaldefs.h>

struct S020a0bcc {
    short* hw;
    char* by;
    short count;
};

// USA: func_020a0bcc
ARM void ClearArrays020a0bcc(struct S020a0bcc* p) {
    short* hw = p->hw;
    char* by = p->by;
    short count = p->count;
    short i;
    for (i = 0; i < count; i++) {
        hw[i] = -1;
        by[i] = 0;
    }
}
