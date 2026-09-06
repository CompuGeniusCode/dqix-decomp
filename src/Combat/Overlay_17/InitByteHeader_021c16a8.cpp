#include <globaldefs.h>

struct ByteHeader0204693c;
void ResetByteHeader(struct ByteHeader0204693c* p);

// USA: func_ov017_021c16a8
ARM void InitByteHeader_021c16a8(unsigned char* self) {
	ResetByteHeader((struct ByteHeader0204693c*)self);
	self[0] = 0x30;
	self[8] = 0;
	self[9] = 0;
}
