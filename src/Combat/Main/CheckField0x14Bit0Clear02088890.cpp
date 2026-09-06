#include <globaldefs.h>

// USA: func_02088890
ARM int CheckField0x14Bit0Clear02088890(unsigned char* obj) {
    return (((int*)obj)[5] & 1) == 0;
}
