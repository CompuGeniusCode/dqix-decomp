#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_ov017_021c07d0(void* p);

struct Obj021c0820 {
	unsigned char pad0[8];
	SafeAllocator alloc;
	int f1c;
	int f20;
	unsigned char b24;
	unsigned char pad2[0xbc - 0x25];
	unsigned char bbc;
};

// USA: func_ov017_021c0820
ARM void InitAllocatorAndClearFields_021c0820(Obj021c0820* p) {
	func_ov017_021c07d0(p);
	p->f20 = 0;
	p->b24 = 0;
	p->f1c = 0;
	p->alloc.ResetAllocatorPointer();
	p->bbc = 0;
}
