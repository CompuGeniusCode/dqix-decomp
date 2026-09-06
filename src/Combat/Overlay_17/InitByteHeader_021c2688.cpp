#include <globaldefs.h>

struct ByteHeader0204693c;
void ResetByteHeader(struct ByteHeader0204693c* p);

// USA: func_ov017_021c2688
ARM void InitByteHeader_021c2688(unsigned char* self) {
	ResetByteHeader((struct ByteHeader0204693c*)self);
	self[0] = 0x44;
	*(int*)(self + 8) = 0;
	self[0xc] = 0;
}
