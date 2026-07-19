#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

struct Obj020979c0;
void InitStructWithZeroId020979f4(Obj020979c0* p);
void TailForward02012da4(AllocatorUnion* alloc, void* data);

extern int data_02114e20;

// USA: func_ov017_021c0364  (semantic: ResetFieldAndForwardAllocator_021c0364)
extern "C" ARM void func_ov017_021c0364(char* self) {
	Obj020979c0* p = *(Obj020979c0**)(self + 0x1c);
	if (p != NULL) {
		InitStructWithZeroId020979f4(p);
	}
	void* signedAlloc = ((SafeAllocator*)(self + 0x8))->GetSignedAllocator();
	((SafeAllocator*)(self + 0x8))->Destroy();
	TailForward02012da4((AllocatorUnion*)&data_02114e20, signedAlloc);
}
