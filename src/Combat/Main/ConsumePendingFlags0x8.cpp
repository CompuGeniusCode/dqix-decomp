#include <globaldefs.h>

int EnableVramBanksFromShadow(unsigned short*);
extern unsigned short data_0211122c;

// USA: func_020c4858
ARM int ConsumePendingFlags0x8(void) {
    return EnableVramBanksFromShadow(&data_0211122c);
}
