#include <globaldefs.h>

extern int data_ov031_0224b94c;
ARM int TransferToBgCharBase020c5c58(int, int, unsigned int);
typedef void (*Callback_022234d8)(void*, int, int);
extern "C" ARM void func_ov031_022234d8(int a0, Callback_022234d8 cb);

// USA: func_ov031_0222a1a4  (semantic: ConfigureBgAndBlendRegs_0222a1a4)
extern "C" ARM void func_ov031_0222a1a4(void) {
	func_ov031_022234d8((int)&data_ov031_0224b94c, (Callback_022234d8)TransferToBgCharBase020c5c58);
	volatile unsigned short* p1 = (volatile unsigned short*)0x4001008;
	volatile unsigned short* p2 = (volatile unsigned short*)0x400000a;
	p1[0] = (p1[0] & ~3) | 3;
	p1[1] = (p1[1] & ~3) | 3;
	p2[0] = (p2[0] & ~3) | 3;
	p2[1] = (p2[1] & ~3) | 3;
}
