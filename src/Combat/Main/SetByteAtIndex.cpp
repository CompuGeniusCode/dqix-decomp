#include <globaldefs.h>

// USA: func_020465d8
ARM void SetByteAtIndex(unsigned char* base, int index, unsigned char value) {
    if (index < 0) {
        return;
    }
    if (index < 0x10) {
        (base + index)[0x8f1] = value;
    }
}
