#include <globaldefs.h>

// USA: func_020d771c
ARM void OrMaskedField24IntoField26(unsigned char* base) {
    unsigned short* a = (unsigned short*)(base + 0xa24);
    unsigned short* b = (unsigned short*)(base + 0xa26);
    *b |= (unsigned short)(*a & 0xff0);
}
