#include <globaldefs.h>

struct ByteHeader0204693c;
void ResetByteHeader(struct ByteHeader0204693c* p);

// USA: func_ov017_021c1acc
ARM void InitByteHeader_021c1acc(unsigned char* self) {
	ResetByteHeader((struct ByteHeader0204693c*)self);
	self[0] = 0x37;
	*(int*)(self + 8) = 0;
	*(int*)(self + 0xc) = 0;
}
