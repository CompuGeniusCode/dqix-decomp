#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Variant02030b0c;
int GetIntFromVariant02030b0c(struct Variant02030b0c* p);

struct Container0215e750;
void InitAllocatedArray_0215e750(struct Container0215e750* obj, SafeAllocator* alloc, int count);

extern int data_ov003_02180cb8;

// USA: func_ov003_0215e4e4  (semantic: InitAllocatedArrayFromVariant_0215e4e4)
extern "C" ARM int func_ov003_0215e4e4(struct Variant02030b0c* v) {
	int count = GetIntFromVariant02030b0c(v);
	SafeAllocator* alloc = (SafeAllocator*)*(int*)&data_ov003_02180cb8;
	struct Container0215e750* obj = (struct Container0215e750*)*(int*)((char*)&data_ov003_02180cb8 + 4);
	InitAllocatedArray_0215e750(obj, alloc, (short)count);
	return 1;
}
