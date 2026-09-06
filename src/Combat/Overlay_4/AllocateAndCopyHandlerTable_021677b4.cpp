#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" void func_ov011_02184a24(void* a, void* b, int c);

struct Buf021677b4 { unsigned int w[0x13]; };
extern struct Buf021677b4 data_ov004_0216ffac;

// USA: func_ov004_021677b4
ARM void AllocateAndCopyHandlerTable_021677b4(SafeAllocator* self, void* target) {
	struct Buf021677b4 buf = data_ov004_0216ffac;
	void* allocated = self->Allocate(0x4c);
	memcpy(allocated, &buf, 0x4c);
	func_ov011_02184a24(target, allocated, 0x13);
}
