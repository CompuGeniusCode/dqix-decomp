#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Container02186e74 {
	SafeAllocator* arr; // 0x0
};

extern int data_ov013_02187dd8[5];

// USA: func_ov013_02186e74
ARM void InitAllocatorArray02186e74(struct Container02186e74* obj, SafeAllocator* allocator) {
	unsigned char i;

	if (allocator == NULL) return;

	obj->arr = (SafeAllocator*)allocator->Allocate(0x64);

	for (i = 0; i < 5; i++) {
		SafeAllocator* base = (SafeAllocator*)((char*)obj->arr + i * 0x14);
		int sz;
		void* ptr;
		base->ResetAllocatorPointer();
		sz = data_ov013_02187dd8[i];
		ptr = allocator->Allocate(sz);
		base->CreateTypeA(ptr, sz);
	}
}
