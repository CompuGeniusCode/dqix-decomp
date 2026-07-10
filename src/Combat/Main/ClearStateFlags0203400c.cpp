#include <globaldefs.h>

void ClearBitsInField0x6c(unsigned char* obj, unsigned int mask);

// USA: func_0203400c
ARM void ClearStateFlags0203400c(unsigned char* obj) {
    ClearBitsInField0x6c(obj, 0x40000);
    obj[0xe0] &= ~0x2;
}
