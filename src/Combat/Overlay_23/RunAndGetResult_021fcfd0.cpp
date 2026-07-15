#include <globaldefs.h>

extern "C" void func_02034d20(void *p);

struct Obj021fcfd0 {
	char pad0[0x1c];
	int result;
};

// USA: func_ov023_021fcfd0
ARM int RunAndGetResult_021fcfd0(struct Obj021fcfd0 *obj) {
	func_02034d20((char*)obj + 0x20);
	return obj->result;
}
