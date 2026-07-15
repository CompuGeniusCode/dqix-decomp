#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
extern void ResetByteHeader(ByteHeader0204693c* p);

struct Obj021c0334 {
	unsigned char byte0;
	unsigned char pad1[7];
	SafeAllocator alloc;
	int f1c;
	int f20;
	unsigned char b24;
};

// USA: func_ov017_021c0334
ARM void InitState40_021c0334(Obj021c0334* p) {
	ResetByteHeader((ByteHeader0204693c*)p);
	p->byte0 = 0x28;
	p->alloc.ResetAllocatorPointer();
	p->f1c = 0;
	p->f20 = 0;
	p->b24 = 0;
}
