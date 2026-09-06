#include <globaldefs.h>
#include "Grotto/Overlay_17/Struct44C8.h"

extern "C" void func_ov017_021a4368(void *p, int v);
extern "C" void func_020439b0(int a, int b);
int GetGlobalField0x1c020421a0();

struct ObjWithField4_021afabc { char pad[4]; int field4; };

// USA: func_ov017_021afabc
ARM void CallField700ThenNotify_021afabc(ObjWithField4_021afabc *obj) {
	Struct_ov017_44C8 *ov = func_ov017_0218b5b0();
	void *p = *(void **)((char *)ov + 0x3000 + 0x700);
	func_ov017_021a4368(p, obj->field4);
	func_020439b0(GetGlobalField0x1c020421a0(), 0);
}
