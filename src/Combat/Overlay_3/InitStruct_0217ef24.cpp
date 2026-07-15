#include <globaldefs.h>

struct ByteHeader0204693c;
void ResetByteHeader(struct ByteHeader0204693c* p);

struct Struct0217ef24 {
	unsigned char byte0;              // 0x0
	char pad1[0xc - 1];
	int field0xc;                     // 0xc
	int field0x10;                    // 0x10
	char pad2[0x28 - 0x14];
	unsigned char field0x28;          // 0x28
	char pad3[0x3a - 0x29];
	unsigned char field0x3a;          // 0x3a
	unsigned char field0x3b;          // 0x3b
};

// USA: func_ov003_0217ef24
ARM void InitStruct_0217ef24(struct Struct0217ef24* p) {
	ResetByteHeader((struct ByteHeader0204693c*)p);
	p->byte0 = 0x2a;
	p->field0xc = 0;
	p->field0x10 = 0;
	p->field0x3a = 0;
	p->field0x3b = 0;
	p->field0x28 = 0xff;
}
