#include <globaldefs.h>

typedef void (*Callback_022234d8)(void*, int, int);
extern "C" ARM void func_ov031_022234d8(int a0, Callback_022234d8 cb);

int TransferMainObjPalette(int arg0, int arg1, unsigned int arg2);
int TransferBg2CharData(int arg0, int arg1, unsigned int arg2);
void CopyToPaletteA(int src, int dstOffset, unsigned int size);
int TransferToBgCharBase020c5c58(int arg0, int arg1, unsigned int arg2);

extern int data_ov031_0224ba0c;
extern int data_ov031_0224ba20;
extern int data_ov031_0224ba38;
extern int data_ov031_0224ba50;

// USA: func_ov031_0222cd14
extern "C" ARM void func_ov031_0222cd14(void) {
    func_ov031_022234d8((int)&data_ov031_0224ba0c, (Callback_022234d8)TransferMainObjPalette);
    func_ov031_022234d8((int)&data_ov031_0224ba20, (Callback_022234d8)TransferBg2CharData);
    func_ov031_022234d8((int)&data_ov031_0224ba38, (Callback_022234d8)CopyToPaletteA);
    func_ov031_022234d8((int)&data_ov031_0224ba50, (Callback_022234d8)TransferToBgCharBase020c5c58);

    volatile unsigned short* subBg0Cnt = (volatile unsigned short*)0x4001008;
    volatile unsigned short* subBg1Cnt = (volatile unsigned short*)0x400100a;
    volatile unsigned short* bg0Cnt = (volatile unsigned short*)0x4000008;
    volatile unsigned short* bg1Cnt = (volatile unsigned short*)0x400000a;
    volatile unsigned short* bg2Cnt = (volatile unsigned short*)0x400000c;

    *subBg0Cnt = (*subBg0Cnt & ~3) | 3;
    *subBg1Cnt = (*subBg1Cnt & ~3) | 3;
    *bg0Cnt = (*bg0Cnt & ~3) | 2;
    *bg1Cnt = (*bg1Cnt & ~3) | 3;
    *bg2Cnt = (*bg2Cnt & ~3) | 3;
}
