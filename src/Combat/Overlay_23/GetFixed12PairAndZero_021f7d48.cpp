#include <globaldefs.h>

struct Triple_021f7d48 {
    unsigned int a;
    unsigned int b;
    unsigned int c;
};

// USA: func_ov023_021f7d48
ARM struct Triple_021f7d48 GetFixed12PairAndZero_021f7d48(void* src) {
    struct Triple_021f7d48 t;
    short a = *(short*)((char*)src + 0x50);
    short b = *(short*)((char*)src + 0x52);
    t.a = a << 0xc;
    t.b = b << 0xc;
    t.c = 0;
    return t;
}
