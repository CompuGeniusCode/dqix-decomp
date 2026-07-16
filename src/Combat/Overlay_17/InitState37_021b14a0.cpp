#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
extern void ResetByteHeader(ByteHeader0204693c* p);

extern int data_ov017_021d83ec;

struct Obj021b14a0 {
	unsigned char byte0;
	unsigned char pad0[7];
	SafeAllocator alloc;
	int f1c;
	unsigned char pad20[0x10];
	unsigned char f30;
	unsigned char f31;
	unsigned char pad32[0x16];
	unsigned char f48;
	unsigned char f49;
	unsigned char f4a;
};

// USA: func_ov017_021b14a0
ARM void InitState37_021b14a0(Obj021b14a0* p) {
	ResetByteHeader((ByteHeader0204693c*)p);
	p->byte0 = 0x2b;
	p->alloc.ResetAllocatorPointer();
	p->f1c = 0;
	data_ov017_021d83ec = 0;
	p->f30 = 0;
	p->f31 = 0;
	p->f48 = 0;
	p->f49 = 1;
	p->f4a = 0;
}
