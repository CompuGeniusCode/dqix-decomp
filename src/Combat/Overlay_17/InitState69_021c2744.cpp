#include <globaldefs.h>

struct ByteHeader0204693c;
extern void ResetByteHeader(ByteHeader0204693c* p);

struct Obj021c2744 {
	unsigned char byte0;
	unsigned char pad1[7];
	unsigned short h8;
	unsigned char pad2[2];
	int fc;
	unsigned char b10;
	unsigned char b11;
	unsigned short h12;
	int f14;
	int f18;
};

// USA: func_ov017_021c2744
ARM void InitState69_021c2744(Obj021c2744* p) {
	ResetByteHeader((ByteHeader0204693c*)p);
	p->byte0 = 0x45;
	p->b10 = 0;
	p->h8 = 0x7d0;
	p->b11 = 0;
	p->f14 = 0;
	p->f18 = -1;
	p->h12 = 0;
	p->fc = 0;
}
