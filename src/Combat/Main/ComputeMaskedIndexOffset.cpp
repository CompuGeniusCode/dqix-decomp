#include <globaldefs.h>

int PopCount32(unsigned int);

// USA: func_020d6884
ARM int ComputeMaskedIndexOffset(void *obj, int value, int base, int bits) {
    return PopCount32(value & ((1 << bits) - 1)) * *(unsigned short*)((char*)obj + 0x810) + base;
}
