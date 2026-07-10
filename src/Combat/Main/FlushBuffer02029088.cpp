#include <globaldefs.h>

extern void* data_020fe9a4;
void CleanInvalidateDataCacheRange(int addr, int size);

// USA: func_02029088
ARM void FlushBuffer02029088() {
    if (data_020fe9a4 == NULL) return;
    CleanInvalidateDataCacheRange((int)data_020fe9a4, 0x6000);
}
