#include <globaldefs.h>

int EnableVramBanksFromShadow(unsigned short* entry);
extern unsigned short data_0211123c;

// USA: func_020c48e4
ARM int DisableSubObjExtPalette(void) {
    *(unsigned int*)0x4001000 &= ~0x80000000;
    return EnableVramBanksFromShadow(&data_0211123c);
}
