#include <globaldefs.h>

extern "C" void func_ov013_021878b0(void* obj);
extern "C" void func_ov013_02187784(void* obj);

// USA: func_ov013_021870c0
ARM void HandleFieldFlagsAndState021870c0(void* obj) {
	unsigned char* o = (unsigned char*)obj;
	if (o[0x69] & 1) {
		func_ov013_021878b0(obj);
	}
	if (o[0x64] == 1) {
		func_ov013_02187784(obj);
	}
}
