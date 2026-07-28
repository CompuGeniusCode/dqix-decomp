#include <globaldefs.h>
#include "System/Memory.h"
#include "Memory/SafeAllocator.h"

void InitStruct0205a444(char* obj);
struct Struct020dfc40;
void ResetStruct020dfc40(struct Struct020dfc40* p);

// USA: func_ov003_0217daf0  (semantic: InitObject_0217daf0)
extern "C" ARM void func_ov003_0217daf0(char* obj) {
	*(int*)(obj + 0x0) = (*(volatile unsigned int*)0x4000000 & 0x1f00) >> 8;
	*(unsigned char*)(obj + 0x4) = 0;
	*(unsigned char*)(obj + 0x5) = 0;
	*(unsigned char*)(obj + 0x6) = 0;
	*(short*)(obj + 0x8) = 1;
	*(int*)(obj + 0xc) = 0;
	*(int*)(obj + 0x14) = 0;
	*(unsigned char*)(obj + 0x30) = 0;
	*(unsigned char*)(obj + 0x31) = 0;
	VectorizedMemset(obj + 0x18, 0, 0x18);
	*(int*)(obj + 0x34) = 0;
	*(int*)(obj + 0x38) = 0;
	InitStruct0205a444(obj + 0x3c);
	*(int*)(obj + 0x90) = 0;
	*(int*)(obj + 0x94) = 0;
	*(int*)(obj + 0x98) = 0;
	*(int*)(obj + 0x9c) = 0;
	*(int*)(obj + 0xa0) = 0;
	((SafeAllocator*)(obj + 0xa4))->ResetAllocatorPointer();
	((SafeAllocator*)(obj + 0xb8))->ResetAllocatorPointer();
	ResetStruct020dfc40((struct Struct020dfc40*)(obj + 0xcc));
}
