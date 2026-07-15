#include <globaldefs.h>
#include "Grotto/Overlay_17/Struct44C8.h"

extern "C" void func_ov017_021a3b40(void *p, int v);
extern "C" void func_0205c96c(void *p, int v);

struct ObjWithField4_021afa70 { char pad[4]; int field4; };

// USA: func_ov017_021afa70
ARM void CallField700ThenReset48_021afa70(ObjWithField4_021afa70 *obj) {
	Struct_ov017_44C8 *ov = func_ov017_0218b5b0();
	void *p = *(void **)((char *)ov + 0x3000 + 0x700);
	func_ov017_021a3b40(p, obj->field4);
	func_0205c96c((char *)obj + 0x48, 0);
}
