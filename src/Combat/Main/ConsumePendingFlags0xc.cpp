#include <globaldefs.h>

int EnableVramBanksFromShadow(unsigned short*);
extern unsigned short data_02111230;

// USA: func_020c4880
ARM int ConsumePendingFlags0xc(void) {
    return EnableVramBanksFromShadow(&data_02111230);
}
