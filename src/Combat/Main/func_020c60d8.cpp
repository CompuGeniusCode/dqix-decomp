#include <globaldefs.h>

int EnableVramBankClearDispcnt0x40000000(void);
extern int data_02111240[];

// USA: func_020c60d8
#pragma optimize_for_size off
extern "C" ARM void func_020c60d8(void) {
    int val = EnableVramBankClearDispcnt0x40000000();
    data_02111240[5] = val;
    switch (val) {
    case 0:
        return;
    case 0x10:
        data_02111240[4] = 0x6880000;
        data_02111240[3] = 0;
        return;
    case 0x40:
        data_02111240[4] = 0x6894000;
        data_02111240[3] = 0x4000;
        return;
    case 0x20:
    case 0x60:
        data_02111240[4] = 0x6890000;
        data_02111240[3] = 0;
        return;
    }
}
