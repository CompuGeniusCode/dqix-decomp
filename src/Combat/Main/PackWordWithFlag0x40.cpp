#include <globaldefs.h>

// USA: func_020c50e4
ARM void PackWordWithFlag0x40(unsigned int* out, unsigned char a, unsigned char b, unsigned char c, int d) {
    *out = ((a | 0x40) | (b << 8)) | ((c | (d << 8)) << 16);
}
