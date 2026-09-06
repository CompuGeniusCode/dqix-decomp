#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
extern void ResetByteHeader(ByteHeader0204693c* p);

struct Obj021b6790 {
	unsigned char byte0;
	char pad1[0x8 - 0x1];
	SafeAllocator allocator;
	char pad2[0x1c - 0x8 - sizeof(SafeAllocator)];
	unsigned char b1c;
	unsigned char b1d;
	unsigned char b1e;
	unsigned char b1f;
	unsigned char b20;
	char pad3[0x24 - 0x21];
	int f24;
};

// USA: func_ov017_021b6790  (semantic: InitObj_021b6790)
extern "C" ARM void func_ov017_021b6790(Obj021b6790* self) {
	ResetByteHeader((ByteHeader0204693c*)self);
	self->byte0 = 0x17;
	self->f24 = 0;
	self->b1f = 0;
	self->b1c = 0;
	self->allocator.ResetAllocatorPointer();
	self->b1d = 0;
	self->b1e = 0xff;
	self->b20 = self->b1e - 0x100;
}
