#include <globaldefs.h>

extern "C" void func_ov006_0215f3d8(void *obj);
extern "C" void func_ov006_0215f740(void *obj);
extern "C" int func_ov006_021595b4(void *obj);

// USA: func_ov006_02159564
ARM int Check02159564(void *obj) {
	*(void**)((char*)obj + 0x44) = (char*)obj + 0x364;
	func_ov006_0215f3d8(obj);
	short *ptr = *(short**)((char*)obj + 0x44);
	if (*(short*)((char*)obj + 0x300 + 0x5e) != *ptr) {
		func_ov006_0215f740(obj);
		return 0;
	}
	return func_ov006_021595b4(obj) != 0;
}
