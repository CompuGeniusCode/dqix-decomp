#include <globaldefs.h>

int EnableVramBanksFromShadow(unsigned short* entry);
extern unsigned short data_02111232;

// USA: func_020c4810
ARM int EnableVramBankClearDispcnt0x40000000(void) {
    *(volatile unsigned int*)0x4000000 &= ~0x40000000;
    return EnableVramBanksFromShadow(&data_02111232);
}
