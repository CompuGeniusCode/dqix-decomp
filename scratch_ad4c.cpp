#include <globaldefs.h>

extern unsigned short data_020fe9cc[];

// USA: func_0202ad4c
ARM void func_0202ad4c(int idx, int bank, unsigned int nibble, const char *str) {
    char c;
    while ((c = *str) != 0) {
        ((unsigned short*)((char*)data_020fe9cc + (bank << 6)))[idx] = (unsigned short)c | ((nibble << 28) >> 16);
        idx++;
        if (idx >= 0x100) return;
        str++;
    }
}
