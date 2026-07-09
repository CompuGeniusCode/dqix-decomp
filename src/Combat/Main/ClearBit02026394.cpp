#include <globaldefs.h>

// USA: func_02026394
ARM void ClearBit02026394(unsigned char* obj, unsigned int index) {
    if (index < 4) {
        obj[0x75D] &= ~(1 << index);
    }
}
