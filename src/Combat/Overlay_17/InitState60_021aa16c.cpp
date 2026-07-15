#include <globaldefs.h>
#include "std_library_functions.h"

struct ByteHeader0204693c;
extern void ResetByteHeader(ByteHeader0204693c* p);
extern "C" void func_ov017_0218b5b0(void);

struct Obj021aa16c { unsigned char byte0; unsigned char pad[7]; unsigned char buf[8]; unsigned char b10; unsigned char b11; unsigned short h12; };

// USA: func_ov017_021aa16c
ARM void InitState60_021aa16c(Obj021aa16c* p) {
	func_ov017_0218b5b0();
	ResetByteHeader((ByteHeader0204693c*)p);
	p->byte0 = 0x3c;
	memset(p->buf, p->byte0 - 0x3d, 8);
	p->b10 = 0;
	p->b11 = 0;
	p->h12 = 0;
}
