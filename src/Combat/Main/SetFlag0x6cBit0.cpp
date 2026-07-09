#include <globaldefs.h>

// USA: func_02037408
ARM void SetFlag0x6cBit0(unsigned char* obj) {
    *(unsigned int*)(obj + 0x6c) |= 1;
}
