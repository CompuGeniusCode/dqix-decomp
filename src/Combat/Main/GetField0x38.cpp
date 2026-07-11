#include <globaldefs.h>

struct S020d2eb0 {
    char pad[0x38];
    int field0x38;
};

// USA: func_020d2eb0
ARM int GetField0x38(struct S020d2eb0* p) {
    return p->field0x38;
}
