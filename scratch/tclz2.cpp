#include <globaldefs.h>

ARM unsigned int TestClz(unsigned int x) {
    unsigned int n = 0;
    if (!(x & 0xffff0000)) { n += 16; x <<= 16; }
    if (!(x & 0xff000000)) { n += 8; x <<= 8; }
    if (!(x & 0xf0000000)) { n += 4; x <<= 4; }
    if (!(x & 0xc0000000)) { n += 2; x <<= 2; }
    if (!(x & 0x80000000)) { n += 1; }
    return n;
}
