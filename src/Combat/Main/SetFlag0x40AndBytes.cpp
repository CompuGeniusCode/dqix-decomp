#include <globaldefs.h>

// USA: func_02088854
ARM void SetFlag0x40AndBytes(unsigned char* obj) {
    obj[0x5f] = 4;
    obj[0x82] = 0;
    *(int*)(obj + 0x14) |= 0x40;
}
