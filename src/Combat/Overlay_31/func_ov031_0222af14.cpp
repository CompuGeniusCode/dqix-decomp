#include <globaldefs.h>

extern int data_ov031_0224b99c;
extern int data_ov031_0224b9b4;
extern int data_ov031_0224b9cc;

typedef void (*Callback_022234d8)(void*, int, int);
extern "C" void func_ov031_022234d8(int a0, Callback_022234d8 cb);

int TransferBg2CharData(int arg0, int arg1, unsigned int arg2);
ARM void CopyToPaletteA(int src, int dstOffset, unsigned int size);
ARM int TransferToBgCharBase020c5c58(int arg0, int arg1, unsigned int arg2);

// USA: func_ov031_0222af14
extern "C" ARM void func_ov031_0222af14(void) {
	func_ov031_022234d8((int)&data_ov031_0224b99c, (Callback_022234d8)TransferBg2CharData);
	func_ov031_022234d8((int)&data_ov031_0224b9b4, (Callback_022234d8)CopyToPaletteA);
	func_ov031_022234d8((int)&data_ov031_0224b9cc, (Callback_022234d8)TransferToBgCharBase020c5c58);
	volatile unsigned short* p3 = (volatile unsigned short*)0x4001008;
	volatile unsigned short* p1 = (volatile unsigned short*)0x400000a;
	volatile unsigned short* p2 = (volatile unsigned short*)0x4000008;
	*p3 = (*p3 & ~3) | 3;
	*(p3 + 1) = (*(p3 + 1) & ~3) | 3;
	*p2 = (*p2 & ~3) | 3;
	*p1 = (*p1 & ~3) | 3;
	*(p1 + 1) = (*(p1 + 1) & ~3) | 3;
}
