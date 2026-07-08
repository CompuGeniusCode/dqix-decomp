#include <globaldefs.h>

// USA: func_020465f0
ARM void SetByteInRange(unsigned char* base, int index, unsigned char value) {
    if (index < 0) {
        return;
    }
    if (index < 0x10) {
        (base + index)[0x902] = value;
    }
}
