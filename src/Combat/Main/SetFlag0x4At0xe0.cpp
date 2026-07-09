#include <globaldefs.h>

struct Flags02033fcc {
    char pad[0xe0];
    unsigned char flags;
};

// USA: func_02033fcc
ARM void SetFlag0x4At0xe0(struct Flags02033fcc* p) {
    p->flags |= 0x4;
}
