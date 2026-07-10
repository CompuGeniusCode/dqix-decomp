#include <globaldefs.h>

int EnableVramBanksFromShadow(unsigned short* entry);
extern unsigned short data_0211123a;

// USA: func_020c48bc
ARM int DisableSubBgExtPalette(void) {
    *(unsigned int*)0x4001000 &= ~0x40000000;
    return EnableVramBanksFromShadow(&data_0211123a);
}
