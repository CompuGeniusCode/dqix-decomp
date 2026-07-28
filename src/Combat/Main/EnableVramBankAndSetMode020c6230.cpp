#include <globaldefs.h>

int EnableVramBankClearDispcnt0x80000000(void);
extern int data_02111240[];

// USA: func_020c6230
extern "C" ARM void func_020c6230(void) {
    int val = EnableVramBankClearDispcnt0x80000000();
    data_02111240[2] = val;
    switch (val) {
    case 0:
        return;
    case 0x20:
        data_02111240[1] = 0x6890000;
        return;
    case 0x40:
        data_02111240[1] = 0x6894000;
        return;
    }
}
