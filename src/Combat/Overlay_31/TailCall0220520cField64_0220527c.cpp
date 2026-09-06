#include <globaldefs.h>

extern "C" int func_ov031_0220520c(int a);

struct Obj0220527c {
	char pad[0x64];
	int field64;
};

// USA: func_ov031_0220527c
ARM int TailCall0220520cField64_0220527c(Obj0220527c* obj) {
	return func_ov031_0220520c(obj->field64);
}
