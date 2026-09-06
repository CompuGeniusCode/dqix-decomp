#include <globaldefs.h>

// USA: func_02033f5c
ARM int GetBit6At0xe0(unsigned char* p) {
    return (unsigned int)(p[0xe0] << 25) >> 31;
}
