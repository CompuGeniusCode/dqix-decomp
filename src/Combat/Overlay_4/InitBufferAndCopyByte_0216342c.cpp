#include <globaldefs.h>
#include "System/Memory.h"

extern "C" int func_ov017_0218b5b0(void);

// USA: func_ov004_0216342c
ARM void InitBufferAndCopyByte_0216342c(void* a) {
	int r = func_ov017_0218b5b0();
	VectorizedMemset(a, 0, 0x1914);
	unsigned char* base = (unsigned char*)a;
	base[0x1000 + 0x8fa] = *(unsigned char*)((char*)r + 0x4000 + 0x2e0);
	base[0x1000 + 0x8fb] = 0;
	base[0x1000 + 0x8fc] = 0;
	base[0x1000 + 0x8fd] = 0;
	base[0x1000 + 0x8fe] = 0;
}
