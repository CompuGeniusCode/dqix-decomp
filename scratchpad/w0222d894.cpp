#include <globaldefs.h>

typedef void (*Callback_0222d894)(void*, int, int);
extern "C" ARM void func_ov031_022234d8(int a0, Callback_0222d894 cb);

extern int TransferMainObjPalette(int, int, unsigned int);
extern int TransferBg2CharData(int, int, unsigned int);
extern int CopyToPaletteA(int, int, unsigned int);
extern int TransferToBgCharBase020c5c58(int, int, unsigned int);

extern unsigned char data_ov031_0224ba80;
extern unsigned char data_ov031_0224ba94;
extern unsigned char data_ov031_0224baac;
extern unsigned char data_ov031_0224bac4;

// USA: func_ov031_0222d894
extern "C" ARM void func_ov031_0222d894(void) {
    func_ov031_022234d8((int)&data_ov031_0224ba80, (Callback_0222d894)TransferMainObjPalette);
    func_ov031_022234d8((int)&data_ov031_0224ba94, (Callback_0222d894)TransferBg2CharData);
    func_ov031_022234d8((int)&data_ov031_0224baac, (Callback_0222d894)CopyToPaletteA);
    func_ov031_022234d8((int)&data_ov031_0224bac4, (Callback_0222d894)TransferToBgCharBase020c5c58);

    volatile unsigned short* subBg0 = (volatile unsigned short*)0x4001008;
    volatile unsigned short* bg0 = (volatile unsigned short*)0x4000008;
    volatile unsigned short* bg1 = (volatile unsigned short*)0x400000a;
    *subBg0 = (*subBg0 & ~3) | 3;
    *(subBg0 + 1) = (*(subBg0 + 1) & ~3) | 3;
    *bg0 = (*bg0 & ~3) | 2;
    *bg1 = (*bg1 & ~3) | 3;
    *(bg1 + 1) = (*(bg1 + 1) & ~3) | 3;
}
