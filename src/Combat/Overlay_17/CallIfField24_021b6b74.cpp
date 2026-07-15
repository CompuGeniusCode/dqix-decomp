#include <globaldefs.h>

struct S021b6b74 { unsigned char pad[0x24]; void* f24; };

extern "C" void func_ov003_02160240(void*);

// USA: func_ov017_021b6b74
ARM void CallIfField24_021b6b74(S021b6b74* obj) {
	void* p = obj->f24;
	if (p) func_ov003_02160240(p);
}
