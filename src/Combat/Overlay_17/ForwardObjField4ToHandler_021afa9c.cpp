#include <globaldefs.h>
#include "Grotto/Overlay_17/Struct44C8.h"

extern "C" void func_ov017_021a3ddc(void* p, void* obj);

struct ObjWithField4_021afa9c { char pad[4]; void* field4; };

// USA: func_ov017_021afa9c
ARM void ForwardObjField4ToHandler_021afa9c(ObjWithField4_021afa9c* obj) {
	void* p = *(void**)((char*)func_ov017_0218b5b0() + 0x3700);
	func_ov017_021a3ddc(p, obj->field4);
}
