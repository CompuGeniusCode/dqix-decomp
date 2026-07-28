#include <globaldefs.h>
#include "System/DMA.h"

void SetVramBankAndDispatch020c43b0(int mode);
extern int data_020f2270;
extern int data_0211125c;

// USA: func_020c68d0
extern "C" ARM void func_020c68d0(void) {
    if (data_020f2270 != -1) {
        AwaitDMACompletion(data_020f2270);
    }
    SetVramBankAndDispatch020c43b0(*(int*)((char*)&data_0211125c + 0x0));
    *(int*)((char*)&data_0211125c + 0x0) = 0;
    *(int*)((char*)&data_0211125c + 0x10) = 0;
}
