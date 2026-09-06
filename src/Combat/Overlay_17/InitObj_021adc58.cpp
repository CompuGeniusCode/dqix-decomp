#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
void ResetByteHeader(struct ByteHeader0204693c* p);

// USA: func_ov017_021adc58
ARM void InitObj_021adc58(unsigned char* self) {
	ResetByteHeader((struct ByteHeader0204693c*)self);
	self[0x0] = 0x21;
	self[0x9] = 0;
	*(short*)(self + 0xe) = 0;
	self[0xa] = 0;
	self[0xc] = 0xf;
	self[0x20] = 0;
	self[0x21] = 0;
	*(short*)(self + 0x28) = 0;
	*(int*)(self + 0x24) = 0;
	*(int*)(self + 0x14) = 0;
	*(int*)(self + 0x18) = 0;
	*(int*)(self + 0x1c) = 0;
	self[0xb] = 0;
	((SafeAllocator*)(self + 0x2c))->ResetAllocatorPointer();
}
