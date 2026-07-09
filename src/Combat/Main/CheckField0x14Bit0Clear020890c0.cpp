#include <globaldefs.h>

// USA: func_020890c0
ARM int CheckField0x14Bit0Clear020890c0(unsigned char* obj) {
    return (((int*)obj)[5] & 1) == 0;
}
