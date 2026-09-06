#include <globaldefs.h>

struct Flags02033fdc {
    char pad[0xe0];
    unsigned char flags;
};

// USA: func_02033fdc
ARM void ClearFlag0x4At0xe0(struct Flags02033fdc* p) {
    p->flags &= ~0x4;
}
