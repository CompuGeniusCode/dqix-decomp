#include <globaldefs.h>
#include "System/Memory.h"

void SetField164_02203164(int v);

// USA: func_ov031_02217f44  (semantic: InitFieldBlock_02217f44)
extern "C" ARM void func_ov031_02217f44(void* self) {
	char* base = (char*)self;
	VectorizedMemset(base + 0x1138, 0, 0x64);
	*(int*)(base + 0x1000 + 0x174) = 0xb68;
	*(int*)(base + 0x1000 + 0x178) = *(int*)(base + 0x1000 + 0x9cc);
	*(int*)(base + 0x1000 + 0x180) = 0x5ea;
	*(int*)(base + 0x1000 + 0x184) = *(int*)(base + 0x1000 + 0x9d0);
	SetField164_02203164((int)(base + 0x1138));
}
