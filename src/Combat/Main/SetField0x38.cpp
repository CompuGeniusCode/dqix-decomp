#include <globaldefs.h>

struct S020466c8 {
    char pad[0x38];
    int field0x38;
};

// USA: func_020466c8
ARM void SetField0x38(struct S020466c8* p, int v) {
    p->field0x38 = v;
}
