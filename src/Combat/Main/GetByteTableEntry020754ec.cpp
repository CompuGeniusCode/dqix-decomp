#include <globaldefs.h>

extern unsigned char data_020e692c[];

// USA: func_020754ec
ARM int GetByteTableEntry020754ec(int i) {
    if (i < 0 || i >= 0x80) return i;
    return data_020e692c[i];
}
