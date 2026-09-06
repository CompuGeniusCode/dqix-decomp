#include <globaldefs.h>
#pragma optimize_for_size off

// USA: func_020c39c8
ARM int GetSignedField020c39c8(volatile unsigned short* p) {
    unsigned short mask = *p & 0xc000;
    if (mask == 0) {
        return 0;
    }
    if (mask == 0x4000) {
        return *p & 0x1f;
    }
    if (mask == 0x8000) {
        return -(*p & 0x1f);
    }
    return 0;
}
