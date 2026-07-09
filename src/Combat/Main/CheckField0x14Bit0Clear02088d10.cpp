#include <globaldefs.h>

// USA: func_02088d10
ARM int CheckField0x14Bit0Clear02088d10(unsigned char* obj) {
    return (((int*)obj)[5] & 1) == 0;
}
