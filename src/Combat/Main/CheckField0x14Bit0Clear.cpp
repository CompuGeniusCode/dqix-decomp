#include <globaldefs.h>

// USA: func_02088930
ARM int CheckField0x14Bit0Clear(unsigned char* obj) {
    return (((int*)obj)[5] & 1) == 0;
}
