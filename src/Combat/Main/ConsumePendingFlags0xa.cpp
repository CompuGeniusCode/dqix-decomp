#include <globaldefs.h>

int EnableVramBanksFromShadow(unsigned short*);
extern unsigned short data_0211122e;

// USA: func_020c486c
ARM int ConsumePendingFlags0xa(void) {
    return EnableVramBanksFromShadow(&data_0211122e);
}
