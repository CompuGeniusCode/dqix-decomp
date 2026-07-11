#include <globaldefs.h>

// USA: func_02039790
ARM int GetByteFieldMasked0x1ce(void* obj, int mask) {
    return *(unsigned char*)((char*)obj + 0x1ce) & mask;
}
