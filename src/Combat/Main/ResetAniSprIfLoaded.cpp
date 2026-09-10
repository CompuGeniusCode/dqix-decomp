#include <globaldefs.h>

struct Struct02047230 {
    unsigned char pad[0x84];
    unsigned char b0 : 1;
    unsigned char b1 : 1;
};

extern "C" void func_0204719c(struct Struct02047230* obj);

// Resets the object, but only when bit 0 of the flag byte at 0x84 is set. That bit means a file is
// loaded: func_02047b40, the parser LoadAniSprFile runs after a successful load, ends by setting
// bits 0 and 1 there. func_0204719c is the full reset: it zeroes the frame cursor at 0x70-0x7c and
// six words at 0x1c-0x30, writes 0x1000 to three fields and 0x1f to 0x82, and clears the low three
// bits of 0x84; the 0x1000 reads as scale and the 0x1f as alpha, but that is inference from the
// constants, as is calling this a cell-animation object. LoadAniSprFile opens with the same guard.
extern "C" ARM void ResetAniSprIfLoaded(struct Struct02047230* obj) {
    if (obj->b0) {
        func_0204719c(obj);
    }
}
