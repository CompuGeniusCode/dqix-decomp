#include <globaldefs.h>

// USA: func_02049f28
ARM void SetSubstructByte0x56(unsigned char* obj) {
    unsigned char* p = *(unsigned char**)(obj + 0x13c);
    if (p != 0) {
        p[0x56] = 1;
    }
}
