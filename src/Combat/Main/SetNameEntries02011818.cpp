#include <globaldefs.h>
#include "System/Memory.h"

struct Src02011818 {
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    char pad3;
    unsigned short f4;
    unsigned char f6;
    signed char f7;
    char pad8[0xb];
    signed char f0x13;
    char pad14[0xc];
    unsigned int f0x20;
    unsigned char f0x24;
    char pad25;
    unsigned short f0x26;
};

// USA: func_02011818
ARM void SetNameEntries02011818(void* obj, struct Src02011818* src) {
    unsigned char* base = (unsigned char*)obj;
    base[0x646c] = 1;
    base[0x646d] = src->f6;
    base[0x6470] = src->f0;
    if (src->f0 == 1) {
        base[0x6471] = src->f1;
        *(unsigned short*)(base + 0x6472) = src->f4;
    } else {
        base[0x6471] = src->f1;
        *(unsigned short*)(base + 0x6472) = src->f2;
        if (src->f0x26 != 0) *(unsigned short*)(base + 0x647e) = src->f0x26;
    }
    if (src->f7 != 0) {
        VectorizedInvertedMemcpy(&src->f7, base + 0x64df, 0xa);
    } else {
        base[0x64df] = 0;
    }
    if (src->f0x13 != 0) {
        VectorizedInvertedMemcpy(&src->f0x13, base + 0x64e9, 0xa);
    } else {
        base[0x64e9] = 0;
    }
    if (src->f0x24 != 0) base[0x647c] = src->f0x24;
    *(unsigned int*)(base + 0x6478) = src->f0x20;
    *(int*)(base + 0x6474) = -1;
}
