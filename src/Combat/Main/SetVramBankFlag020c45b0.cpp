#include <globaldefs.h>

extern "C" int func_020c3aac(unsigned short);

struct VramBankState02111224_020c45b0 {
    unsigned short field0;
    unsigned char pad[16];
    unsigned short field0x12;
};
extern struct VramBankState02111224_020c45b0 data_02111224;

// USA: func_020c45b0  (semantic: SetVramBankFlag020c45b0)
#pragma optimize_for_size off
extern "C" ARM int func_020c45b0(int mode) {
    data_02111224.field0 = (unsigned short)(~mode & (data_02111224.field0 | data_02111224.field0x12));
    data_02111224.field0x12 = (unsigned short)mode;

    switch (mode) {
    case 0:
        break;
    case 4:
        *(volatile unsigned char*)0x4000242 = 0x84;
        break;
    case 0x180:
        *(volatile unsigned char*)0x4000249 = 0x81;
        // fallthrough
    case 0x80:
        *(volatile unsigned char*)0x4000248 = 0x81;
        break;
    default:
        break;
    }

    return func_020c3aac(data_02111224.field0);
}
