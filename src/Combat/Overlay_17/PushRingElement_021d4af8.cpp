#include <globaldefs.h>
#include "std_library_functions.h"

struct Elem021d4af8 { int f0; int f4; int f8; };
struct Arg021d4af8 { int f0; char pad4[4]; int f8; int fc; };

struct Ctx021d4af8 {
	char pad0[0x14];
	int f14;
	char pad1[0x28 - 0x14 - 4];
	struct Elem021d4af8* f28;
	struct Elem021d4af8* f2c;
	int f30;
	struct Arg021d4af8* f34;
	char pad2[0x48 - 0x34 - 4];
	int f48;
};

extern "C" void func_0200159c(int code);

// USA: func_ov017_021d4af8  (semantic: PushRingElement_021d4af8)
extern "C" ARM int func_ov017_021d4af8(struct Ctx021d4af8* self, struct Arg021d4af8* arg, int value) {
	struct Elem021d4af8* dst = self->f28;
	if (dst >= self->f2c) {
		func_0200159c(-2);
	}
	dst->f0 = value;
	self->f28->f8 = (int)self->f34;
	self->f28->f4 = self->f30;

	self->f30 = self->f14 - (arg->fc << 3);
	self->f14 = self->f30 + (arg->f8 << 3);
	self->f34 = arg;
	self->f28 = (struct Elem021d4af8*)((char*)self->f28 + 0xc);

	memset((void*)(self->f30 + (self->f34->fc << 3)), 0, (self->f34->f8 - self->f34->fc) << 3);

	return self->f48 + arg->f0;
}
