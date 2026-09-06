#include <globaldefs.h>

// USA: func_02039d68
ARM int CheckFlag0x1ceBit2Set(unsigned char* obj) {
    return (obj[0x1ce] & 4) != 0;
}
