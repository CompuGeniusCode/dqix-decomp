#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

void TailForward02012da4(AllocatorUnion* alloc, void* data);

extern int data_02114e20;

struct Obj021aeea8 {
	char pad[0x2c];
	SafeAllocator allocator;
};

// USA: func_ov017_021aeea8  (semantic: DestroySafeAllocatorField2c_021aeea8)
extern "C" ARM void func_ov017_021aeea8(struct Obj021aeea8* self) {
	void* p = self->allocator.GetSignedAllocator();
	if (p != NULL) {
		self->allocator.Destroy();
		TailForward02012da4((AllocatorUnion*)&data_02114e20, p);
	}
}
