#include <globaldefs.h>

typedef void (*Callback_022234d8)(void*, int, int);
extern "C" ARM void func_ov031_022234d8(int a0, Callback_022234d8 cb);
extern int TransferToBgCharBase020c5c58(int, int, unsigned int);

extern unsigned char data_ov031_0224bda0;

// USA: func_ov031_02234118
extern "C" ARM void func_ov031_02234118(void) {
    func_ov031_022234d8((int)&data_ov031_0224bda0, (Callback_022234d8)TransferToBgCharBase020c5c58);
    volatile unsigned short* subBg0 = (volatile unsigned short*)0x4001008;
    volatile unsigned short* bg1 = (volatile unsigned short*)0x400000a;
    *subBg0 = (*subBg0 & ~3) | 3;
    *(subBg0 + 1) = (*(subBg0 + 1) & ~3) | 3;
    *bg1 = (*bg1 & ~3) | 3;
    *(bg1 + 1) = (*(bg1 + 1) & ~3) | 3;
}
