#include <globaldefs.h>

// USA: func_020263b0
ARM void SetBit020263b0(unsigned char* obj, unsigned int index) {
    if (index < 4) {
        obj[0x75D] |= 1 << index;
    }
}
