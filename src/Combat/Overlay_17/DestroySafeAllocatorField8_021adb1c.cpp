#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

void TailForward02012da4(AllocatorUnion* alloc, void* data);

extern int data_02114e20;

struct Obj021adb1c {
	char pad[0x8];
	SafeAllocator allocator;
};

// USA: func_ov017_021adb1c  (semantic: DestroySafeAllocatorField8_021adb1c)
extern "C" ARM void func_ov017_021adb1c(struct Obj021adb1c* self) {
	void* p = self->allocator.GetSignedAllocator();
	if (p != NULL) {
		self->allocator.Destroy();
		TailForward02012da4((AllocatorUnion*)&data_02114e20, p);
	}
}
