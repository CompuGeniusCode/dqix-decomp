#include <globaldefs.h>
#include "System/DMA.h"

void SetSubObjExtPaletteFieldAndDispatch020c4748(unsigned short value);
extern int data_020f2270;
extern int data_02111240;

// USA: func_020c6460  (semantic: ResetSubObjExtPaletteAndDma_020c6460)
extern "C" ARM void func_020c6460(void) {
    if (data_020f2270 != -1) {
        AwaitDMACompletion(data_020f2270);
    }
    ((void (*)(int))SetSubObjExtPaletteFieldAndDispatch020c4748)(*(int*)((char*)&data_02111240 + 0x18));
    *(int*)((char*)&data_02111240 + 0x18) = 0;
}
