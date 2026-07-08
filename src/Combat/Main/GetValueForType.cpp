#include <globaldefs.h>

// USA: func_020a4220
ARM int GetValueForType(unsigned char* p) {
    unsigned char t = p[1];
    int r = 1;
    if (t == 1) {
        r = p[0x65];
    } else if (t == 2) {
        r = p[0x56];
    }
    return r;
}
