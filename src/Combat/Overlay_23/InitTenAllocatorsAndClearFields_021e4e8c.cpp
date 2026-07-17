#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_02034bc4(void* p);

// USA: func_ov023_021e4e8c
ARM void InitTenAllocatorsAndClearFields_021e4e8c(void* obj) {
	char *base = (char*)obj;
	base[0xc11] = 0;
	for (int i = 0; i < 10; i++) {
		func_02034bc4(base + i * 0xac);
		((SafeAllocator*)(base + 0x6b8 + i * 0x14))->ResetAllocatorPointer();
	}
	((SafeAllocator*)(base + 0x780))->ResetAllocatorPointer();
	base[0xc10] = 0;
	for (int i = 0; i < 12; i++) {
		*(short*)(base + 0xbf4 + i * 2) = -1;
	}
	base[0xc12] = 0;
	base[0xc15] = 0;
	*(int*)(base + 0xc18) = 0;
	base[0xc14] = 1;
}
