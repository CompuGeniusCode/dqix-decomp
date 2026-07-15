#include <globaldefs.h>

extern "C" void func_02035a2c(void* obj, int flag);

struct Obj20_021fcfe8 { char pad[0xc]; unsigned char flags; };

// USA: func_ov023_021fcfe8
ARM void CallFunc02035a2cIfNotFlag3Set_021fcfe8(struct Obj20_021fcfe8* obj) {
	if (obj->flags & 8) return;
	func_02035a2c((char*)obj + 0x20, 1);
}
