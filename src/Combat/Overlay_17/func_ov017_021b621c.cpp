#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" int func_ov017_0218b5b0(void);

struct ByteHeader0204693c;
void ResetByteHeader(struct ByteHeader0204693c* p);

struct Handle02046c98;
void EnsureHandleAllocated02046c98(struct Handle02046c98* h);

extern "C" void func_02046e70(void* obj, int a, int b);

// USA: func_ov017_021b621c  (semantic: Init021b621c)
extern "C" ARM void func_ov017_021b621c(unsigned char* self, int a, int b) {
	func_ov017_0218b5b0();
	ResetByteHeader((struct ByteHeader0204693c*)self);
	self[0] = 0x16;
	func_02046e70(self + 0xc, a, b);
	EnsureHandleAllocated02046c98((struct Handle02046c98*)(self + 0xc));
	self[0xfc] = 0;
	*(short*)(self + 0xfe) = -1;
	if (a == 0) self[0xfd] = 0xf;
	else self[0xfd] = 0;
	self[8] = 1;
	*(short*)(self + 0x100) = -1;
}
