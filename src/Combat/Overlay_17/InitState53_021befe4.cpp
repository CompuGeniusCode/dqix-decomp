#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
extern void ResetByteHeader(ByteHeader0204693c* p);

struct List020727d8 { void* entries; short capacity; short count; };
extern void ResetListHeader020727d8(List020727d8* list);

struct Obj021befe4 {
	unsigned char byte0;
	unsigned char pad1[7];
	int f8;
	List020727d8 listAtC;
	SafeAllocator alloc;
};

// USA: func_ov017_021befe4
ARM void InitState53_021befe4(Obj021befe4* p) {
	ResetByteHeader((ByteHeader0204693c*)p);
	p->byte0 = 0x35;
	p->f8 = 0;
	ResetListHeader020727d8(&p->listAtC);
	p->alloc.ResetAllocatorPointer();
}
