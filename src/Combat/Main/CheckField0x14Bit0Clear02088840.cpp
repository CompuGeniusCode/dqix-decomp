#include <globaldefs.h>

// USA: func_02088840
ARM int CheckField0x14Bit0Clear02088840(unsigned char* obj) {
    return (((int*)obj)[5] & 1) == 0;
}
