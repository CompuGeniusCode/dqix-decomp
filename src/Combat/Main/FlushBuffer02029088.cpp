#include <globaldefs.h>

extern void* data_020fe9a4;
void CleanInvalidateCacheRange(const void* addr, unsigned int size);

// USA: func_02029088
ARM void FlushBuffer02029088() {
    if (data_020fe9a4 == NULL) return;
    CleanInvalidateCacheRange((const void*)((int)data_020fe9a4), 0x6000);
}
