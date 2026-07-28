#include <globaldefs.h>
#include "System/DMA.h"

void SetSubBgExtPaletteFieldAndDispatch020c46c8(unsigned short value);
extern int data_020f2270;
extern int data_02111240;

// USA: func_020c63a4  (semantic: ResetSubBgExtPaletteAndDma_020c63a4)
extern "C" ARM void func_020c63a4(void) {
    if (data_020f2270 != -1) {
        AwaitDMACompletion(data_020f2270);
    }
    ((void (*)(int))SetSubBgExtPaletteFieldAndDispatch020c46c8)(data_02111240);
    data_02111240 = 0;
}
