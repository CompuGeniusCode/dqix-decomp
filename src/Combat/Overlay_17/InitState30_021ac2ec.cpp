#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
extern void ResetByteHeader(ByteHeader0204693c* p);

struct Obj021ac2ec {
	unsigned char byte0;
	unsigned char pad1[7];
	int f8;
	int fc;
	SafeAllocator alloc;
	int f24;
	unsigned char b28;
	unsigned char b29;
};

// USA: func_ov017_021ac2ec
ARM void InitState30_021ac2ec(Obj021ac2ec* p) {
	ResetByteHeader((ByteHeader0204693c*)p);
	p->byte0 = 0x1e;
	p->f8 = 0;
	p->fc = 0;
	p->alloc.ResetAllocatorPointer();
	p->f24 = -1;
	p->b28 = 0;
	p->b29 = 0;
}
