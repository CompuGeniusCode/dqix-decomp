#include <globaldefs.h>
// USA: func_0207c694
ARM unsigned char GetByteFromArray0xc28(unsigned char *base, unsigned int index) {
    if (index > 7) return -1;
    return *(base + index + 0xc28);
}
