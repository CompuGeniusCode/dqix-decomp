#include <globaldefs.h>

// USA: func_02088cb8
ARM int IsFlag0x14Bit0Clear02088cb8(unsigned char* obj) {
    return (((int*)obj)[5] & 1) == 0;
}
