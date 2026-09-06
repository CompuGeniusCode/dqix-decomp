#include <globaldefs.h>

struct ByteFlags02033f2c {
    char pad[0xe0];
    unsigned char flags_e0;
};

// USA: func_02033f2c
ARM void ClearFlags0x40And0x80At0xe0(struct ByteFlags02033f2c* p) {
    p->flags_e0 &= ~0x40;
    p->flags_e0 &= ~0x80;
}
