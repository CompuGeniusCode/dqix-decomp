#include <globaldefs.h>

struct Flags020340b4 {
    char pad[0xc2];
    unsigned char flags;
};

// USA: func_020340b4
ARM void SetFlag0x80At0xc2(struct Flags020340b4* p) {
    p->flags |= 0x80;
}
