#include <globaldefs.h>

extern "C" void func_0204b04c(void* obj, void* p);

struct Obj28_021f7884 { char pad[0xc]; unsigned char flags; };

// USA: func_ov023_021f7884
ARM void CallFunc0204b04cIfNotFlag0Set_021f7884(struct Obj28_021f7884* obj) {
	if (obj->flags & 1) return;
	func_0204b04c((char*)obj + 0x28, NULL);
}
