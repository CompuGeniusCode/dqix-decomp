#include <globaldefs.h>

int EnableVramBanksFromShadow(unsigned short*);
extern unsigned short data_02111238;

// USA: func_020c48a8
ARM int ConsumePendingFlags0x14(void) {
    return EnableVramBanksFromShadow(&data_02111238);
}
