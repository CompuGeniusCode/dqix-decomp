#include <globaldefs.h>

typedef void (*Callback_022234d8)(void*, int, int);
extern "C" ARM void func_ov031_022234d8(int a0, Callback_022234d8 cb);

extern "C" int LoadToMainObjStandardPalette(int arg0, int arg1, unsigned int arg2);
extern "C" int LoadToMainBG2CharacterData(int arg0, int arg1, unsigned int arg2);
extern "C" void LoadToMainBGStandardPalette(int src, int dstOffset, unsigned int size);
extern "C" int LoadToMainBG2ScreenData(int arg0, int arg1, unsigned int arg2);

extern int data_ov031_0224ba80;
extern int data_ov031_0224ba94;
extern int data_ov031_0224baac;
extern int data_ov031_0224bac4;

// USA: func_ov031_0222d894
extern "C" ARM void func_ov031_0222d894(void) {
    func_ov031_022234d8((int)&data_ov031_0224ba80, (Callback_022234d8)LoadToMainObjStandardPalette);
    func_ov031_022234d8((int)&data_ov031_0224ba94, (Callback_022234d8)LoadToMainBG2CharacterData);
    func_ov031_022234d8((int)&data_ov031_0224baac, (Callback_022234d8)LoadToMainBGStandardPalette);
    func_ov031_022234d8((int)&data_ov031_0224bac4, (Callback_022234d8)LoadToMainBG2ScreenData);

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
