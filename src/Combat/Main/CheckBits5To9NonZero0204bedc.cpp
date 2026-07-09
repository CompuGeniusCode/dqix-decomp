#include <globaldefs.h>

// USA: func_0204bedc
ARM int CheckBits5To9NonZero0204bedc(unsigned short* obj) {
    return ((obj[1] & 0x3e0) >> 5) != 0;
}
