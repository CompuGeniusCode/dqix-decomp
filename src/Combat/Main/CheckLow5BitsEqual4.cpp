#include <globaldefs.h>

// USA: func_0204be08
ARM int CheckLow5BitsEqual4(unsigned short* obj) {
    return (obj[1] & 0x1f) == 4;
}
