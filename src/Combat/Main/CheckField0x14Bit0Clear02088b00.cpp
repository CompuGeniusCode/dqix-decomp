#include <globaldefs.h>

// USA: func_02088b00
ARM int CheckField0x14Bit0Clear02088b00(unsigned char* obj) {
    return (((int*)obj)[5] & 1) == 0;
}
