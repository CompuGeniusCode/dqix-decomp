#include <globaldefs.h>

// USA: func_02037a94
ARM void SetBitsInField0x6c(unsigned char* obj, unsigned int mask) {
    *(unsigned int*)(obj + 0x6c) |= mask;
}
