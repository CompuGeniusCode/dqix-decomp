#include <globaldefs.h>

extern "C" void func_ov031_022234d8(void* data, void* fn);
extern "C" int func_ov031_02223478(void* buf);
extern "C" int func_ov031_0223b61c(int t, int a, int b);
extern "C" void func_ov031_0223cb68(int a, int b);

extern "C" void _Z22TransferMainObjPaletteiij(int, int, unsigned int);
extern "C" void _Z19TransferBg2CharDataiij(int, int, unsigned int);
extern "C" void _Z14CopyToPaletteAiij(int, int, unsigned int);
extern "C" void _Z28TransferToBgCharBase020c5c58iij(int, int, unsigned int);

extern unsigned char data_ov031_0224906c[22];
extern unsigned char data_ov031_0224bc94[1];
extern unsigned char data_ov031_0224bca8[1];
extern unsigned char data_ov031_0224bcc0[1];
extern unsigned char data_ov031_0224bcd8[1];

struct Ptr02290cc0 { void* field0; void* field4; };
extern Ptr02290cc0 data_ov031_02290cc0;

// USA: func_ov031_02232568
extern "C" ARM void func_ov031_02232568(void) {
	unsigned char buf[24];
	int n = 11;
	unsigned char* d = buf;
	unsigned char* s = data_ov031_0224906c;
	do {
		unsigned char a = s[0];
		unsigned char b = s[1];
		s += 2;
		d[0] = a;
		d[1] = b;
		d += 2;
	} while (--n);

	func_ov031_022234d8(data_ov031_0224bc94, (void*)_Z22TransferMainObjPaletteiij);
	func_ov031_022234d8(data_ov031_0224bca8, (void*)_Z19TransferBg2CharDataiij);
	func_ov031_022234d8(data_ov031_0224bcc0, (void*)_Z14CopyToPaletteAiij);
	func_ov031_022234d8(data_ov031_0224bcd8, (void*)_Z28TransferToBgCharBase020c5c58iij);

	int t = func_ov031_02223478(buf);

	int r = func_ov031_0223b61c(t, 0, 4);
	*(int*)data_ov031_02290cc0.field4 = r;
	func_ov031_0223cb68(1, 0x10);

	unsigned short* p2 = (unsigned short*)0x4001008;
	unsigned short* p1 = (unsigned short*)0x400000a;
	p2[0] = (p2[0] & ~3) | 3;
	p2[1] = (p2[1] & ~3) | 3;
	p1[0] = (p1[0] & ~3) | 3;
	p1[1] = (p1[1] & ~3) | 3;
}
