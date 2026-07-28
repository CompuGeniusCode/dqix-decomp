#include <globaldefs.h>

extern "C" ARM void func_ov031_022234d8(int a0, void* cb);
extern int TransferToBgCharBase020c5c58(int arg0, int arg1, unsigned int arg2);

extern int data_ov031_0224b884;

// USA: func_ov031_022289a4  (semantic: FlushAndSetBgPriorities_022289a4)
extern "C" ARM void func_ov031_022289a4(void) {
    func_ov031_022234d8((int)&data_ov031_0224b884, (void*)TransferToBgCharBase020c5c58);

    volatile unsigned short* subBg0 = (volatile unsigned short*)0x4001008;
    volatile unsigned short* bg0 = (volatile unsigned short*)0x4000008;
    volatile unsigned short* bg1 = (volatile unsigned short*)0x400000a;
    *subBg0 = (*subBg0 & ~3) | 3;
    *(subBg0 + 1) = (*(subBg0 + 1) & ~3) | 3;
    *bg0 = (*bg0 & ~3) | 3;
    *bg1 = (*bg1 & ~3) | 3;
    *(bg1 + 1) = (*(bg1 + 1) & ~3) | 3;
}
