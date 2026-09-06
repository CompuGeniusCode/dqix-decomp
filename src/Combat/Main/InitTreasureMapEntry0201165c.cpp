#include <globaldefs.h>
#include "System/Memory.h"

struct Payload0201165c {
    int d;
    int e;
    int f;
    unsigned char g;
    char pad1[3];
    unsigned char h;
};

// USA: func_0201165c
ARM void InitTreasureMapEntry0201165c(char* obj, const void* src, int c, struct Payload0201165c p) {
    VectorizedInvertedMemcpy(src, obj + 0x450 + 0x6000, 0x1c);
    *(int*)(obj + 0x6000 + 0x3f0) = c;
    *(int*)(obj + 0x6000 + 0x3f4) = p.d;
    *(int*)(obj + 0x6000 + 0x3f8) = p.e;
    *(int*)(obj + 0x6000 + 0x3fc) = p.f;
    *(unsigned char*)(obj + 0x6000 + 0x3e9) = p.g;
    *(unsigned char*)(obj + 0x6000 + 0x3ea) = p.h;
    *(unsigned char*)(obj + 0x6000 + 0x3e4) = 1;
    *(unsigned char*)(obj + 0x6000 + 0x3e5) = 1;
}
