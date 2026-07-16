#include <globaldefs.h>

struct Entry021573c8 {
    short id;
    char pad[0x16 - 0x2];
    unsigned char flags16;
    char pad2[0x18 - 0x17];
};

extern "C" struct Entry021573c8* func_ov006_02157368(void* c, int id);

// USA: func_ov006_021573c8
ARM void ClearFlagsForIds_021573c8(void* c) {
    struct Entry021573c8* e;
    e = func_ov006_02157368(c, 0x50);
    if (e != NULL) {
        e->flags16 &= ~0x1;
    }
    e = func_ov006_02157368(c, 0x4f);
    if (e != NULL) {
        e->flags16 &= ~0x1;
    }
    e = func_ov006_02157368(c, 0xe);
    if (e != NULL) {
        e->flags16 &= ~0x1;
    }
    e = func_ov006_02157368(c, 0xf);
    if (e != NULL) {
        e->flags16 &= ~0x1;
    }
    e = func_ov006_02157368(c, 0x15);
    if (e != NULL) {
        e->flags16 |= 0x1;
    }
}
