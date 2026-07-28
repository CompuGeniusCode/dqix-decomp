#include <globaldefs.h>

extern int TransferBg2CharData(int arg0, int arg1, unsigned int arg2);
extern void CopyToPaletteA(int src, int dstOffset, unsigned int size);
extern int TransferToBgCharBase020c5c58(int arg0, int arg1, unsigned int arg2);
typedef void (*Callback_022234d8)(void*, int, int);
extern "C" void func_ov031_022234d8(int a0, Callback_022234d8 cb);

extern unsigned char data_ov031_0224bc0c;
extern unsigned char data_ov031_0224bc24;
extern unsigned char data_ov031_0224bc3c;

// USA: func_ov031_02231c0c
extern "C" ARM void TransferGraphicsAndSetBgPriority_02231c0c(void) {
	func_ov031_022234d8((int)&data_ov031_0224bc0c, (Callback_022234d8)TransferBg2CharData);
	func_ov031_022234d8((int)&data_ov031_0224bc24, (Callback_022234d8)CopyToPaletteA);
	func_ov031_022234d8((int)&data_ov031_0224bc3c, (Callback_022234d8)TransferToBgCharBase020c5c58);
	volatile unsigned short* subBg0 = (volatile unsigned short*)0x4001008;
	volatile unsigned short* bg0 = (volatile unsigned short*)0x4000008;
	volatile unsigned short* bg1 = (volatile unsigned short*)0x400000a;
	*subBg0 = (*subBg0 & ~3) | 3;
	*(subBg0 + 1) = (*(subBg0 + 1) & ~3) | 3;
	*bg0 = (*bg0 & ~3) | 3;
	*bg1 = (*bg1 & ~3) | 3;
	*(bg1 + 1) = (*(bg1 + 1) & ~3) | 3;
}
