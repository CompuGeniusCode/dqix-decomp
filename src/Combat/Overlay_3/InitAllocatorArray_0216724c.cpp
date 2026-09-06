#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Obj0216724c {
	void* field0;
	SafeAllocator* allocArray;
};

struct Sizes3_0216724c { unsigned int v[3]; };
extern struct Sizes3_0216724c data_ov003_0217f4e4;

// USA: func_ov003_0216724c  (semantic: InitAllocatorArray_0216724c)
extern "C" ARM void func_ov003_0216724c(struct Obj0216724c* obj, SafeAllocator* alloc) {
	int i;
	struct Sizes3_0216724c sizes;
	if (alloc == NULL) return;
	obj->allocArray = (SafeAllocator*)alloc->Allocate(0x3c);
	sizes = data_ov003_0217f4e4;
	for (i = 0; i < 3; i++) {
		unsigned int sz = sizes.v[i];
		void* p = alloc->Allocate(sz);
		obj->allocArray[i].CreateTypeA(p, sz);
	}
	if (obj->field0 == NULL) {
		obj->field0 = alloc->Allocate(0x4000);
	}
}
