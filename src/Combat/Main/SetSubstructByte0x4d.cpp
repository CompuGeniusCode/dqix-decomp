#include <globaldefs.h>

// USA: func_0204947c
ARM void SetSubstructByte0x4d(unsigned char* obj, unsigned char value) {
    unsigned char* p = *(unsigned char**)(obj + 0x13c);
    if (p != 0) {
        p[0x4d] = value;
    }
}
