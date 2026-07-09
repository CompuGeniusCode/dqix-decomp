#include <globaldefs.h>

// USA: func_02011b3c
ARM void SetBitsInField0x63dc(void* obj, unsigned char mask) {
    unsigned char* base = (unsigned char*)obj;
    (base + 0x6000)[0x3dc] |= mask;
}
