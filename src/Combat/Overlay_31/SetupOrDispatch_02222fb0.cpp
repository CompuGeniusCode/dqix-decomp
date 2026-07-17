#include <globaldefs.h>

extern "C" void func_ov031_0223e2b8(void*, void*);
extern "C" void func_ov031_02223000();
extern void* data_ov031_02250ba8;

// USA: func_ov031_02222fb0
ARM void SetupOrDispatch_02222fb0(void* arg) {
	*(signed char*)((char*)data_ov031_02250ba8 + 0x16) = -1;
	*(unsigned short*)((char*)data_ov031_02250ba8 + 0x14) += 1;
	if (*(unsigned short*)((char*)data_ov031_02250ba8 + 0x14) < 4) return;
	*(unsigned short*)((char*)data_ov031_02250ba8 + 0x14) = 0;
	func_ov031_0223e2b8(arg, (void*)func_ov031_02223000);
}
