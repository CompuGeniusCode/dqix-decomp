#include <globaldefs.h>

extern short data_020fe9cc[];

// USA: func_0202ad4c
ARM void FillPaletteEntries_0202ad4c(int startIndex, unsigned int param1, unsigned int param2, const signed char* str) {
    short* table = (short*)((char*)data_020fe9cc + (param1 << 6));
    int idx = startIndex;
    while (*str != 0) {
        table[idx] = (unsigned short)*str | ((param2 & 0xf) << 12);
        idx++;
        if (idx >= 0x100) return;
        str++;
    }
}
