#include <globaldefs.h>

// USA: func_ov031_0220c09c
ARM unsigned int ReadHiWord0220c09c(volatile unsigned short* p) {
    unsigned short lo = p[0];
    unsigned short hi = p[-1];
    (void)lo;
    return (unsigned int)hi << 16;
}
