#include <globaldefs.h>

// USA: func_02088ba0
ARM int IsFlag0x14Bit0Clear02088ba0(unsigned char* obj) {
    return (((int*)obj)[5] & 1) == 0;
}
