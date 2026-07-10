#include <globaldefs.h>

int EnableVramBanksFromShadow(unsigned short* entry);
extern unsigned short data_02111234;

// USA: func_020c4834
ARM int EnableVramBankClearDispcnt0x80000000(void) {
    *(volatile unsigned int*)0x4000000 &= ~0x80000000;
    return EnableVramBanksFromShadow(&data_02111234);
}
