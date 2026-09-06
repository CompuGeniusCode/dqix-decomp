#include <globaldefs.h>

// USA: func_02039dbc
ARM void ClearFlag0x1ceBit0x8(unsigned char* obj) {
    obj[0x1ce] &= ~8;
}
