#include <globaldefs.h>
#include "System/DMA.h"

void SetVramFieldAndDispatch020c42c8(int value);
extern int data_020f2270;
extern int data_0211125c;

// USA: func_020c6728
extern "C" ARM void func_020c6728(void) {
    if (data_020f2270 != -1) {
        AwaitDMACompletion(data_020f2270);
    }
    SetVramFieldAndDispatch020c42c8(*(int*)((char*)&data_0211125c + 0xc));
    *(int*)((char*)&data_0211125c + 0xc) = 0;
    *(int*)((char*)&data_0211125c + 0x8) = 0;
}
