#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
extern void ResetByteHeader(ByteHeader0204693c* p);

struct Obj021abb68 {
	unsigned char byte0;
	unsigned char pad1[7];
	unsigned char b8;
	unsigned char pad2;
	unsigned short ha;
	unsigned char bc;
	unsigned char bd;
	unsigned char pad3[2];
	SafeAllocator alloc;
	int f24;
};

// USA: func_ov017_021abb68
ARM void InitState28_021abb68(Obj021abb68* p, unsigned char b) {
	ResetByteHeader((ByteHeader0204693c*)p);
	p->byte0 = 0x1c;
	p->b8 = 0;
	p->ha = 0;
	p->bc = b;
	p->f24 = -1;
	p->bd = 0;
	p->alloc.ResetAllocatorPointer();
}
