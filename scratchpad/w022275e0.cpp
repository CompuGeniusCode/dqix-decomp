#include <globaldefs.h>

extern "C" ARM void* func_ov031_0223cf4c(unsigned int len, int align);
ARM int FillSlotArrayField4_0223beec(int n, int base, int stride);
extern void* data_ov031_02290c40;

// USA: func_ov031_022275e0
ARM void AllocateAndInitField60_022275e0(void) {
    data_ov031_02290c40 = func_ov031_0223cf4c(0x64, 4);
    *(int*)((char*)data_ov031_02290c40 + 0x60) = FillSlotArrayField4_0223beec(8, (int)data_ov031_02290c40, 0xc);
}
