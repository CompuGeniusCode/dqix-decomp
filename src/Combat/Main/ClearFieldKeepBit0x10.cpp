#include <globaldefs.h>

// USA: func_02011af0
ARM void ClearFieldKeepBit0x10(void* obj) {
    unsigned char* base = (unsigned char*)obj;
    int keep = ((base + 0x6000)[0x3dc] & 0x10) != 0;
    (base + 0x6000)[0x3dc] = 0;
    if (keep) {
        (base + 0x6000)[0x3dc] |= 0x10;
    }
}
