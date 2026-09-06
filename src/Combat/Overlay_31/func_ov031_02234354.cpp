#include <globaldefs.h>

typedef void (*Callback_022234d8)(void*, int, int);

extern "C" void func_ov031_022234d8(int a0, Callback_022234d8 cb);
extern "C" extern int LoadToMainBG2ScreenData(int arg0, int arg1, unsigned int arg2);

extern int data_ov031_0224bdb4;

// USA: func_ov031_02234354  (semantic: FlushAndSetBgPrioritiesToBack_02234354)
extern "C" ARM void func_ov031_02234354(void) {
    func_ov031_022234d8((int)&data_ov031_0224bdb4, (Callback_022234d8)LoadToMainBG2ScreenData);
    volatile unsigned short* subBg0 = (volatile unsigned short*)0x4001008;
    volatile unsigned short* bg0 = (volatile unsigned short*)0x4000008;
    volatile unsigned short* bg1 = (volatile unsigned short*)0x400000a;
    *subBg0 = (*subBg0 & ~3) | 3;
    *(subBg0 + 1) = (*(subBg0 + 1) & ~3) | 3;
    *bg0 = (*bg0 & ~3) | 3;
    *bg1 = (*bg1 & ~3) | 3;
    *(bg1 + 1) = (*(bg1 + 1) & ~3) | 3;
}
