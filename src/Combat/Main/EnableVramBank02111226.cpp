#include <globaldefs.h>

int EnableVramBanksFromShadow(unsigned short* entry);
extern unsigned short data_02111226;

// USA: func_020c47fc
ARM int EnableVramBank02111226(void) {
    return EnableVramBanksFromShadow(&data_02111226);
}
