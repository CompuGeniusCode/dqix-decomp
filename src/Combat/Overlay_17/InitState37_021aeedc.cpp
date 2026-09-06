#include <globaldefs.h>

struct ByteHeader0204693c;
extern void ResetByteHeader(ByteHeader0204693c* p);

struct Struct021aeedc {
	unsigned char byte0;
	unsigned char pad1[7];
	unsigned char b8;
	unsigned char pad2[6];
	signed char bf;
	signed char b10;
	unsigned char pad3;
	unsigned short h12;
};

// USA: func_ov017_021aeedc
ARM void InitState37_021aeedc(Struct021aeedc* p) {
	signed char neg1 = 0 - 1;
	ResetByteHeader((ByteHeader0204693c*)p);
	p->byte0 = 0x25;
	p->b8 = 0;
	p->bf = neg1;
	p->h12 = 0;
	p->b10 = neg1;
}
