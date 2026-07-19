#include <globaldefs.h>

void CleanInvalidateCacheRange(const void* addr, unsigned int size);
int TransferMainOam(int arg0, int arg1, unsigned int arg2);
int TransferSubOam(int arg0, int arg1, unsigned int arg2);

extern void* data_ov031_02290d60;

// USA: func_ov031_0223d9c4
ARM void FlushAndTransferOam_0223d9c4(void) {
	CleanInvalidateCacheRange(data_ov031_02290d60, 0x800);
	TransferMainOam((int)data_ov031_02290d60, 0, 0x400);
	TransferSubOam((int)((char*)data_ov031_02290d60 + 0x400), 0, 0x400);
}
