#include <globaldefs.h>

// USA: func_ov031_0220c0ac
ARM unsigned int ReadWord_0220c0ac(volatile unsigned short* p) {
    unsigned short lo = p[0];
    unsigned short mid = p[-1];
    unsigned short hi = p[-2];
    (void)lo;
    return (unsigned int)hi | ((unsigned int)mid << 16);
}
