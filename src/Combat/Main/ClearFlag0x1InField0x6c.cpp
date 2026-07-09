#include <globaldefs.h>

// USA: func_020373f8
ARM void ClearFlag0x1InField0x6c(unsigned char* obj) {
    *(unsigned int*)(obj + 0x6c) &= ~0x1;
}
