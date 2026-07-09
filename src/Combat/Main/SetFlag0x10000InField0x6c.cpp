#include <globaldefs.h>

// USA: func_02037310
ARM void SetFlag0x10000InField0x6c(unsigned char* obj) {
    *(unsigned int*)(obj + 0x6c) |= 0x10000;
}
