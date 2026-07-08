#include <globaldefs.h>

// USA: func_02037aa4
ARM void ClearBitsInField0x6c(unsigned char* obj, unsigned int mask) {
    *(unsigned int*)(obj + 0x6c) &= ~mask;
}
