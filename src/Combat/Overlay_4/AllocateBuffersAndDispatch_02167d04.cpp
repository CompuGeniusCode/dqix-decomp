#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void* func_ov011_021845f8(void* a, int b);
extern "C" void func_ov004_02167b78(void* a, int b);

struct DataStruct02171024 { void* field0; void* field4; void* field8; };
extern struct DataStruct02171024 data_ov004_02171024;

// USA: func_ov004_02167d04
ARM int AllocateBuffersAndDispatch_02167d04(void* a) {
	void* base = func_ov011_021845f8(a, 0);
	if (base != NULL) {
		SafeAllocator* alloc = (SafeAllocator*)((char*)base + 4);
		data_ov004_02171024.field4 = alloc->Allocate(0xc);
		data_ov004_02171024.field0 = alloc->Allocate(0x80);
		data_ov004_02171024.field8 = alloc->Allocate(0x80);
		func_ov004_02167b78(a, 0);
	}
	return 0;
}
