#include <globaldefs.h>

// USA: func_020a2cc4
ARM int CheckField0x245Bit0x2Set(unsigned char* obj) {
    return (obj[0x245] & 2) != 0;
}
