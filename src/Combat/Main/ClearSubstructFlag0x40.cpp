#include <globaldefs.h>

// USA: func_0204950c
ARM void ClearSubstructFlag0x40(unsigned char* obj) {
    int* p = *(int**)(obj + 0x13c);
    p[8] &= ~0x40;
}
