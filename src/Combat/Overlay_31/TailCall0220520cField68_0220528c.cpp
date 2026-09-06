#include <globaldefs.h>

extern "C" int func_ov031_0220520c(int a);

struct Obj0220528c {
	char pad[0x68];
	int field68;
};

// USA: func_ov031_0220528c
ARM int TailCall0220520cField68_0220528c(Obj0220528c* obj) {
	return func_ov031_0220520c(obj->field68);
}
