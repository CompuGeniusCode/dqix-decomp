#include <globaldefs.h>

// USA: func_02088d9c
ARM void ClearFlag0x100AndBytes7dA0(unsigned char* obj) {
    *(int*)(obj + 0x18) &= ~0x100;
    obj[0x7d] = 0;
    obj[0xa0] = 0;
}
