#include <globaldefs.h>

extern "C" int func_020c490c(unsigned short*);
extern unsigned short data_02111234;

// USA: func_020c4a38
ARM int ClearDispcntBit31AndResetVramBanks() {
    *(volatile unsigned int*)0x4000000 &= ~0x80000000;
    return func_020c490c(&data_02111234);
}
