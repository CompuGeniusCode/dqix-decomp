#include <globaldefs.h>

extern "C" void func_ov031_022234d8(void* data, void* fn);
extern "C" int func_ov031_02223478(void* buf);
extern "C" int func_ov031_0223b61c(int t, int a, int b);

extern "C" void LoadToMainBG2CharacterData(int, int, unsigned int);
extern "C" void LoadToMainBGStandardPalette(int, int, unsigned int);
extern "C" void LoadToMainBG2ScreenData(int, int, unsigned int);

extern unsigned char data_ov031_02248dae[22];
extern unsigned char data_ov031_0224b82c[1];
extern unsigned char data_ov031_0224b844[1];
extern unsigned char data_ov031_0224b85c[1];
extern unsigned char data_ov031_02290c50[8];

// USA: func_ov031_022280a0
extern "C" ARM void func_ov031_022280a0(void) {
	unsigned char buf[24];
	int n = 11;
	unsigned char* d = buf;
	unsigned char* s = data_ov031_02248dae;
	do {
		unsigned char a = s[0];
		unsigned char b = s[1];
		s += 2;
		d[0] = a;
		d[1] = b;
		d += 2;
	} while (--n);

	func_ov031_022234d8(data_ov031_0224b82c, (void*)LoadToMainBG2CharacterData);
	func_ov031_022234d8(data_ov031_0224b844, (void*)LoadToMainBGStandardPalette);
	func_ov031_022234d8(data_ov031_0224b85c, (void*)LoadToMainBG2ScreenData);

	int t = func_ov031_02223478(buf);
	int r = func_ov031_0223b61c(t, 0, 4);
	*(int*)(data_ov031_02290c50 + 4) = r;

	unsigned short* p2 = (unsigned short*)0x4001008;
	unsigned short* p1 = (unsigned short*)0x400000a;
	p2[0] = (p2[0] & ~3) | 3;
	p2[1] = (p2[1] & ~3) | 3;
	p1[0] = (p1[0] & ~3) | 3;
	p1[1] = (p1[1] & ~3) | 3;
}
