#include <globaldefs.h>

void SetBitsInField0x6c(unsigned char* obj, unsigned int mask);

// USA: func_02033fec
ARM void SetBits0x40000AndFlag0x2(unsigned char* obj) {
    SetBitsInField0x6c(obj, 0x40000);
    obj[0xe0] |= 0x2;
}
