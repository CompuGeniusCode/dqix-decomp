#include <globaldefs.h>

// USA: func_020374c4
ARM void StoreVec3AsShortsAt0x5c(unsigned char* dst, int* src) {
    *(unsigned short*)(dst + 0x5c) = src[0];
    *(unsigned short*)(dst + 0x5e) = src[1];
    *(unsigned short*)(dst + 0x60) = src[2];
}
