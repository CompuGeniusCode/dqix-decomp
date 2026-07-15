#include <globaldefs.h>

// USA: func_ov000_02163378
ARM void CopyFourAndSetFlag02163378(void* dst, int* src, unsigned char val) {
    int i;
    for (i = 0; i < 4; i++) {
        *(int*)((char*)dst + i * 4 + 0x5000 + 0x758) = src[i];
    }
    *((unsigned char*)dst + 0x5000 + 0x76c) = val;
    *(int*)((char*)dst + 0x5000 + 0x5f4) |= 0x4000;
}
