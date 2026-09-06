#include <globaldefs.h>

// USA: func_020888e0
ARM int CheckField0x14Bit0Clear020888e0(unsigned char* obj) {
    return (((int*)obj)[5] & 1) == 0;
}
