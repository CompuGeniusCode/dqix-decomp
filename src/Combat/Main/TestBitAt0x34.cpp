#include <globaldefs.h>

// USA: func_020a35e0
ARM int TestBitAt0x34(unsigned char* obj, unsigned int index) {
    if (index >= 4) {
        return 0;
    }
    return obj[0x34] & (1 << index);
}
