#include <globaldefs.h>

// USA: func_02088d68
ARM int CheckField0x14Bit0Clear02088d68(unsigned char* obj) {
    return (((int*)obj)[5] & 1) == 0;
}
