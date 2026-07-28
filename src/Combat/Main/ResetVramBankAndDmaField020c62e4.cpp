#include <globaldefs.h>
#include "System/DMA.h"

void SetVramBankFlag020c4044(unsigned int flag);
extern int data_020f2270;
extern int data_02111240[];

// USA: func_020c62e4
extern "C" ARM void func_020c62e4(void) {
    if (data_020f2270 != -1) {
        AwaitDMACompletion(data_020f2270);
    }
    SetVramBankFlag020c4044((unsigned int)data_02111240[2]);
    data_02111240[2] = 0;
    data_02111240[1] = 0;
}
