#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

extern "C" void* func_02057924(void* obj);
extern "C" void func_02057f00(void* obj, int index);
extern "C" void func_020a0c0c(void);
void TailForward02012da4(AllocatorUnion* alloc, void* data);

extern int data_02114e20;

struct Obj021ac2a8 {
	char pad[0x10];
	SafeAllocator allocator;
};

// USA: func_ov017_021ac2a8  (semantic: FinalizeState30_021ac2a8)
extern "C" ARM void func_ov017_021ac2a8(struct Obj021ac2a8* self) {
	func_02057f00(func_02057924(self), 5);

	void* p = self->allocator.GetSignedAllocator();
	if (p != NULL) {
		self->allocator.Destroy();
		TailForward02012da4((AllocatorUnion*)&data_02114e20, p);
	}

	func_020a0c0c();
}
