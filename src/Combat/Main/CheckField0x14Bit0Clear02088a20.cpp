#include <globaldefs.h>

// USA: func_02088a20
ARM int CheckField0x14Bit0Clear02088a20(unsigned char* obj) {
    return (((int*)obj)[5] & 1) == 0;
}
