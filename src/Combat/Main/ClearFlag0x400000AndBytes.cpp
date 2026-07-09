#include <globaldefs.h>

// USA: func_02088b34
ARM void ClearFlag0x400000AndBytes(unsigned char* obj) {
    ((int*)obj)[5] &= ~0x400000;
    obj[0x67] = 0;
    obj[0x8a] = 0;
}
