#include <globaldefs.h>

int EnableVramBanksFromShadow(unsigned short*);
extern unsigned short data_02111236;

// USA: func_020c4894
ARM int ConsumePendingFlags0x12(void) {
    return EnableVramBanksFromShadow(&data_02111236);
}
