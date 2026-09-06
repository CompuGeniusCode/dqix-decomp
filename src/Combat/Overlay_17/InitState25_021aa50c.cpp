#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
extern void ResetByteHeader(ByteHeader0204693c* p);

struct Obj021aa50c {
	unsigned char byte0;
	unsigned char pad0[7];
	int f8;
	int fc;
	int f10;
	int f14;
	int f18;
	int f1c;
	int f20;
	SafeAllocator alloc;
	int f38;
	int f3c;
	int f40;
	int f44;
	short f48;
	short f4a;
	short f4c;
	short pad4e;
	int f50;
	int f54;
	int f58;
	unsigned char f5c;
	unsigned char pad5d[3];
	int f60;
	int f64;
};

// USA: func_ov017_021aa50c
ARM void InitState25_021aa50c(Obj021aa50c* p) {
	ResetByteHeader((ByteHeader0204693c*)p);
	p->byte0 = 0x1a;
	p->fc = (*(volatile unsigned int*)0x4000000 & 0x1f00) >> 8;
	p->f8 = 0;
	p->f18 = 0;
	p->f20 = 0;
	p->f1c = 0;
	p->alloc.ResetAllocatorPointer();
	p->f38 = 0;
	p->f3c = 0;
	p->f40 = 0;
	p->f44 = 0;
	p->f48 = -1;
	p->f4a = -1;
	p->f4c = -0xb;
	p->f50 = -1;
	p->f10 = 0;
	p->f14 = 0;
	p->f54 = 0;
	p->f58 = 0;
	p->f5c = 0;
	p->f60 = 0;
	p->f64 = 0;
}
