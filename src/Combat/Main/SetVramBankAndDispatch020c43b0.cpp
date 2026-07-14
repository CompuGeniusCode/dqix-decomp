#include <globaldefs.h>

extern "C" void func_020c3aac(unsigned short);

struct GlobalBlock2111224_020c43b0 {
    unsigned short field0;
    unsigned char pad[10];
    unsigned short field0xc;
};
extern struct GlobalBlock2111224_020c43b0 data_02111224;

// USA: func_020c43b0
#pragma optimize_for_size off
ARM void SetVramBankAndDispatch020c43b0(int mode) {
    data_02111224.field0 = (unsigned short)(~mode & (data_02111224.field0 | data_02111224.field0xc));
    data_02111224.field0xc = (unsigned short)mode;

    switch (mode) {
    case 3:
        *(volatile unsigned char*)0x4000240 = 0x93;
        // fallthrough
    case 2:
        *(volatile unsigned char*)0x4000241 = 0x9b;
        *(volatile unsigned short*)0x4000060 |= 0x4000;
        break;
    case 12:
        *(volatile unsigned char*)0x4000242 = 0x93;
        // fallthrough
    case 8:
        *(volatile unsigned char*)0x4000243 = 0x9b;
        *(volatile unsigned short*)0x4000060 |= 0x4000;
        break;
    case 0:
        *(volatile unsigned short*)0x4000060 &= ~0x4000;
        break;
    case 1:
        *(volatile unsigned char*)0x4000240 = 0x9b;
        *(volatile unsigned short*)0x4000060 |= 0x4000;
        break;
    case 4:
        *(volatile unsigned char*)0x4000242 = 0x9b;
        *(volatile unsigned short*)0x4000060 |= 0x4000;
        break;
    default:
        break;
    }

    func_020c3aac(data_02111224.field0);
}
