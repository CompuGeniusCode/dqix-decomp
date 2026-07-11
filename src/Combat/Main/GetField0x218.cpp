#include <globaldefs.h>

struct S020a3570 {
    char pad[0x218];
    int field0x218;
};

// USA: func_020a3570
ARM int GetField0x218(struct S020a3570* p) {
    return p->field0x218;
}
