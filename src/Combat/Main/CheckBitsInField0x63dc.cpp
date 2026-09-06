#include <globaldefs.h>

// USA: func_02011b50
ARM int CheckBitsInField0x63dc(void* obj, int mask) {
    unsigned char* base = (unsigned char*)obj;
    return ((base + 0x6000)[0x3dc] & mask) != 0;
}
