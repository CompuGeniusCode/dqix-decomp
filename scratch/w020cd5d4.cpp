#include <globaldefs.h>

struct Blk4_020cd5d4 { unsigned int v[4]; };

// USA: func_020cd5d4
ARM void RestoreDivSqrtState020cd5d4(char* src) {
    char* dst = (char*)0x4000290;
    *(Blk4_020cd5d4*)dst = *(Blk4_020cd5d4*)src;
    *(volatile unsigned short*)(dst - 0x10) = *(unsigned short*)(src + 0x18);
    *(volatile unsigned short*)(dst + 0x20) = *(unsigned short*)(src + 0x1a);
    *(long long*)(dst + 0x28) = *(long long*)(src + 0x10);
}
