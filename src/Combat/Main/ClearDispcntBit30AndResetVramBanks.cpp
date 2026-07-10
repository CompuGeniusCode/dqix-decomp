#include <globaldefs.h>

extern "C" int func_020c490c(unsigned short*);
extern unsigned short data_02111232;

// USA: func_020c4a14
ARM int ClearDispcntBit30AndResetVramBanks() {
    *(volatile unsigned int*)0x4000000 &= ~0x40000000;
    return func_020c490c(&data_02111232);
}
