#include <globaldefs.h>

extern unsigned int data_020eef30;

// KEEP-NAME: the ROM symbol is the C library name, not a func_ tag.
// USA: func_02003d14
extern "C" ARM int rand() {
    data_020eef30 = data_020eef30 * 0x41c64e6d + 0x3039;
    return (int)(0x7fff & (data_020eef30 >> 16));
}
