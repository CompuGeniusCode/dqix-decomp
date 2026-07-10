#include <globaldefs.h>

extern unsigned int data_0214e5e4;

// USA: func_020dc07c
ARM void PushOneBitField0x3c() {
    unsigned int* base = &data_0214e5e4;
    base[15] = (base[15] << 1) | 1;
}
