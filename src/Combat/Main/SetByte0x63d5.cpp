#include <globaldefs.h>

// USA: func_02012040
ARM void SetByte0x63d5(void* obj) {
    unsigned char* base = (unsigned char*)obj;
    (base + 0x6000)[0x3d5] = 1;
}
