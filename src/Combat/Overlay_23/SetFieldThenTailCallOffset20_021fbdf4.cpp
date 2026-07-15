#include <globaldefs.h>

extern "C" void func_ov023_021ddf5c(void *obj, unsigned char v);

struct Obj021fbdf4 {
	char pad[0x79a];
	unsigned char field;
};

// USA: func_ov023_021fbdf4
ARM void SetFieldThenTailCallOffset20_021fbdf4(struct Obj021fbdf4 *obj, unsigned char v) {
	obj->field = v;
	func_ov023_021ddf5c((char*)obj + 0x20, v);
}
