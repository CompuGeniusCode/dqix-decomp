#include <globaldefs.h>

// USA: func_02088af0
ARM void ClearFlag0x200000(unsigned char* obj) {
    *(int*)(obj + 0x14) &= ~0x200000;
}
