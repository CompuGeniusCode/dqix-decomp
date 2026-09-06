#include <globaldefs.h>

extern "C" void* func_ov023_021e2418(void* obj, int val);

struct Obj021e23d0 {
    char pad0[3];
    unsigned char lowNibble : 4;
    unsigned char highNibble : 4;
    char pad1[0xc - 4];
    int field0xc;
};

// USA: func_ov023_021e23d0
ARM void SetEntryFields_021e23d0(void* obj, int val, int f0xc, unsigned char lowNib, unsigned char highNib) {
    struct Obj021e23d0* e = (struct Obj021e23d0*)func_ov023_021e2418(obj, val);
    if (e == NULL) return;
    e->field0xc = f0xc;
    e->lowNibble = lowNib;
    e->highNibble = highNib;
}
