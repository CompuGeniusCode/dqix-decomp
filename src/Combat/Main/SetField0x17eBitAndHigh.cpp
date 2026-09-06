#include <globaldefs.h>

// USA: func_02079710
ARM void SetField0x17eBitAndHigh(unsigned char* obj, int bit, int cond) {
    obj[0x17e] |= (1 << bit);
    if (cond) {
        obj[0x17e] |= (1 << (bit + 4));
    }
}
