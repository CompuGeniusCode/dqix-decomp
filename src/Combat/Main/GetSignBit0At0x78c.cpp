#include <globaldefs.h>

// USA: func_0202fe58
ARM int GetSignBit0At0x78c(unsigned char* p) {
    return (*(int*)(p + 0x78c) << 31) >> 31;
}
