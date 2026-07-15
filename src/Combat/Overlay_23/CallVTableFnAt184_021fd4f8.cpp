#include <globaldefs.h>

struct VTable021fd4f8 {
	char pad[0xb8];
	void (*fn)(void*);
};

struct Obj021fd4f8 {
	struct VTable021fd4f8 *vtable;
};

// USA: func_ov023_021fd4f8
ARM void CallVTableFnAt184_021fd4f8(struct Obj021fd4f8 *obj) {
	obj->vtable->fn(obj);
}
