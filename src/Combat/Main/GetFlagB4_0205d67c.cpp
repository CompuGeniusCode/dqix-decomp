#include <globaldefs.h>

struct Struct_0205d67c {
    char pad0[0x98];
    int field98;
    int field9C;
    char pad1[0x14];
    unsigned char fieldB4;
};

// USA: func_0205d67c
ARM int GetFlagB4_0205d67c(struct Struct_0205d67c* p) {
    if (p->field98 == 0) return 0;
    return p->field9C != 0 ? p->fieldB4 : 0;
}
