#include <globaldefs.h>

// USA: func_02088980
ARM int CheckField0x14Bit0Clear02088980(unsigned char* obj) {
    return (((int*)obj)[5] & 1) == 0;
}
