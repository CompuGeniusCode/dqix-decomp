#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

void DestroyActiveAllocators_0215aa5c(void);
void TailForward02012da4(AllocatorUnion* alloc, void* data);
extern int data_02114e20;

// USA: func_ov017_021bb108
extern "C" ARM void func_ov017_021bb108(char* self) {
	void* p1 = ((SafeAllocator*)(self + 0x7c))->GetSignedAllocator();
	if (p1 != NULL) {
		DestroyActiveAllocators_0215aa5c();
		void* p2 = ((SafeAllocator*)(self + 0x124))->GetSignedAllocator();
		if (p2 != NULL) {
			((SafeAllocator*)(self + 0x124))->Destroy();
			((SafeAllocator*)(self + 0x7c))->Free(p2);
		}
		void* p3 = ((SafeAllocator*)(self + 0x7c))->GetSignedAllocator();
		((SafeAllocator*)(self + 0x7c))->Destroy();
		TailForward02012da4((AllocatorUnion*)&data_02114e20, p3);
	}
	if (*(SafeAllocator**)(self + 0x138) == NULL) return;
	void* p4 = (*(SafeAllocator**)(self + 0x138))->GetSignedAllocator();
	if (p4 == NULL) return;
	(*(SafeAllocator**)(self + 0x138))->Destroy();
	TailForward02012da4((AllocatorUnion*)&data_02114e20, p4);
	*(SafeAllocator**)(self + 0x138) = NULL;
}
