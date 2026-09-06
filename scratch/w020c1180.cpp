#include <globaldefs.h>

// USA: func_020c1180
ARM void SetIdentity33_020c1180(unsigned int* p) {
    p[8] = 0x1000;
    *p++ = 0x1000;
    *p++ = 0;
    *p++ = 0;
    *p++ = 0;
    *p++ = 0x1000;
    *p++ = 0;
    *p++ = 0;
    *p++ = 0;
}
