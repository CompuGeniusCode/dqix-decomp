#include <globaldefs.h>

// USA: func_0201bfc0
ARM int TestFlagBitAt0x2744(unsigned char* obj, int bit) {
    return obj[0x2744] & (1 << bit);
}
