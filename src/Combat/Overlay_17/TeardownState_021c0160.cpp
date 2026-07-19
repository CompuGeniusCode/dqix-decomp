#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

void TailForward02012da4(AllocatorUnion* alloc, void* data);

extern int data_ov017_021d8474;
extern int data_02114e20;

struct Obj021c0160 {
	char pad[0x8];
	SafeAllocator allocator;
};

// USA: func_ov017_021c0160  (semantic: TeardownState_021c0160)
extern "C" ARM void func_ov017_021c0160(struct Obj021c0160* self) {
	data_ov017_021d8474 = 0;

	void* p = self->allocator.GetSignedAllocator();
	if (p != NULL) {
		self->allocator.Destroy();
		TailForward02012da4((AllocatorUnion*)&data_02114e20, p);
	}
}
