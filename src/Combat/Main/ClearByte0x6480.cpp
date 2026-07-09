#include <globaldefs.h>

// USA: func_020119e8
ARM void ClearByte0x6480(void* obj) {
    unsigned char* base = (unsigned char*)obj;
    (base + 0x6000)[0x480] = 0;
}
