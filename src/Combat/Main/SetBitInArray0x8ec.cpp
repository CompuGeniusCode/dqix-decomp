#include <globaldefs.h>

// USA: func_02083acc
ARM void SetBitInArray0x8ec(unsigned char* obj, int index) {
    unsigned char* p = obj + 0x8ec;
    p[index / 8] |= 1 << (index % 8);
}
