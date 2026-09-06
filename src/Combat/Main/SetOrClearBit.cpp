#include <globaldefs.h>

// USA: func_0201bf98
ARM void SetOrClearBit(unsigned char* obj, int bit, int set) {
    if (set) {
        obj[0x2744] |= (1 << bit);
    } else {
        obj[0x2744] &= ~(1 << bit);
    }
}
