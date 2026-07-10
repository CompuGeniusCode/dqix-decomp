#include <globaldefs.h>

void ClearFlag0x4AndBytes(unsigned char* obj);

// USA: func_02088c10
ARM void SetFlag0x2ClearFlag0x4(unsigned char* obj) {
    obj[0x6c] = 5;
    obj[0x8f] = 0;
    *(int*)(obj + 0x18) |= 0x2;
    ClearFlag0x4AndBytes(obj);
}
