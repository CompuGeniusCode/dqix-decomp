#include <globaldefs.h>

// USA: func_02083b60
ARM void SetBitInArray0x910(unsigned char* obj, int index) {
    unsigned char* p = obj + 0x910;
    p[index / 8] |= 1 << (index % 8);
}
