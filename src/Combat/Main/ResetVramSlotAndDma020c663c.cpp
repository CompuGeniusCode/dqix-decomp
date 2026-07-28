#include <globaldefs.h>
#include "System/DMA.h"

extern "C" void func_020c40f0(int handle);
extern int data_020f2270;
extern int data_0211125c;

// USA: func_020c663c  (semantic: ResetVramSlotAndDma020c663c)
extern "C" ARM void func_020c663c(void) {
    if (data_020f2270 != -1) {
        AwaitDMACompletion(data_020f2270);
    }
    func_020c40f0(*(int*)((char*)&data_0211125c + 0x14));
    *(int*)((char*)&data_0211125c + 0x1c) = 0;
    *(int*)((char*)&data_0211125c + 0x18) = 0;
    *(int*)((char*)&data_0211125c + 0x4) = 0;
    *(int*)((char*)&data_0211125c + 0x14) = 0;
}
