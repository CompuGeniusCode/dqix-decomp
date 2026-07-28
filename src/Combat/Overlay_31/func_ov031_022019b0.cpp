#include <globaldefs.h>

extern "C" int func_ov031_02200730(unsigned int);
extern "C" int func_ov031_02200bfc(void);
extern "C" void func_ov031_02200ccc(int);
extern unsigned int ComputeNormalizedChecksum_02200684(void*, unsigned int);
extern "C" int func_ov031_0220116c(void*, int, int, int, unsigned int, int);

struct Struct022019b0 { unsigned char pad0[0xc]; unsigned short f0c; unsigned short f0e; };

#define SwapBytes16_022019b0(v) (unsigned short)(((v) >> 8) | ((v) << 8))

// USA: func_ov031_022019b0  (semantic: HandlePacketType8_022019b0)

#pragma optimize_for_size off
extern "C" ARM void func_ov031_022019b0(Struct022019b0* a0, void* a1, int a2) {
	unsigned int combined = ((unsigned int)SwapBytes16_022019b0(a0->f0c) << 16) | SwapBytes16_022019b0(a0->f0e);

	int r = func_ov031_02200730(combined);
	if (r == 0) return;

	if (func_ov031_02200bfc() == 0) {
		func_ov031_02200ccc(r);
		return;
	}

	*(unsigned char*)a1 = 0;
	*(unsigned short*)((char*)a1 + 2) = 0;
	int cs = (int)ComputeNormalizedChecksum_02200684(a1, a2);
	*(unsigned short*)((char*)a1 + 2) = (unsigned short)((cs >> 8) | (cs << 8));

	unsigned int combined2 = ((unsigned int)SwapBytes16_022019b0(a0->f0c) << 16) | SwapBytes16_022019b0(a0->f0e);

	func_ov031_0220116c(a1, a2, 0, 0, combined2, 1);
}
