#include <globaldefs.h>

struct Vec3Inner_0215377c { unsigned int v[3]; };

extern "C" void __clear(void* ptr, int size);

// USA: func_ov004_0215377c  (semantic: InitVec3FromStack_0215377c)
extern "C" ARM void func_ov004_0215377c(Vec3Inner_0215377c* dst) {
	Vec3Inner_0215377c local;
	__clear(&local, 0xc);
	*dst = local;
}
