#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
extern void ResetByteHeader(ByteHeader0204693c* p);

struct Obj021a6608 {
	unsigned char byte0;
	unsigned char pad1[7];
	unsigned char b8;
	unsigned char b9;
	unsigned char ba;
	unsigned char bb;
	unsigned char bc;
	unsigned char pad2;
	unsigned short he;
	SafeAllocator alloc;
};

// USA: func_ov017_021a6608
ARM void InitState61_021a6608(Obj021a6608* p) {
	ResetByteHeader((ByteHeader0204693c*)p);
	p->byte0 = 0x3d;
	p->b8 = 0;
	p->he = (unsigned short)(p->b8 - 1);
	p->b9 = 0;
	p->ba = 0;
	p->bb = 0;
	p->bc = 0;
	p->alloc.ResetAllocatorPointer();
}
