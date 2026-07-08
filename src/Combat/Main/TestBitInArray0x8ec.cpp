#include <globaldefs.h>

// USA: func_02083b00
ARM int TestBitInArray0x8ec(unsigned char* obj, int index) {
    unsigned char* p = obj + index / 8;
    return (1 << (index % 8)) & p[0x8ec];
}
