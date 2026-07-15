#include <globaldefs.h>

struct S021604d0 { char pad[0x4a3]; unsigned char flag4a3; };

extern "C" void func_ov003_0216052c(S021604d0* obj);
extern "C" void func_ov003_02160678(S021604d0* obj);

// USA: func_ov003_021604d0
ARM void UpdateIfFlag4a3_021604d0(S021604d0* obj) {
	if (obj->flag4a3 != 0) {
		func_ov003_0216052c(obj);
		func_ov003_02160678(obj);
	}
}
