#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
extern void ResetByteHeader(ByteHeader0204693c* p);

struct Obj021ba90c {
	unsigned char byte0;
	unsigned char pad1[7];
	SafeAllocator alloc;
	int f1c;
	unsigned char b20;
	unsigned char b21;
	unsigned char b22;
	unsigned char b23;
};

// USA: func_ov017_021ba90c
ARM void InitState16_021ba90c(Obj021ba90c* p) {
	ResetByteHeader((ByteHeader0204693c*)p);
	p->byte0 = 0x10;
	p->b22 = 0;
	p->alloc.ResetAllocatorPointer();
	p->f1c = 0;
	p->b20 = 0;
	p->b21 = 0;
	p->b23 = 0xff;
}
