#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct Block80_0215502c {
	unsigned int words[20];
};

extern Block80_0215502c data_ov004_0216fa8c;

extern "C" int func_ov011_02184a24(int, void*, int);

// USA: func_ov004_0215502c
ARM int AllocateAndDispatch20_0215502c(SafeAllocator* alloc, int arg) {
	Block80_0215502c local = data_ov004_0216fa8c;
	void* buf = alloc->Allocate(0x50);
	memcpy(buf, &local, 0x50);
	return func_ov011_02184a24(arg, buf, 0x14);
}
