#include <globaldefs.h>

// USA: func_ov023_021fb498
ARM void SetShortsFromDiv4096_021fb498(void* dst, int* src) {
    *(unsigned short*)((char*)dst + 0x28) = (unsigned short)((float)src[0] / 4096.0f);
    *(unsigned short*)((char*)dst + 0x2a) = (unsigned short)((float)src[1] / 4096.0f);
}
