#include <globaldefs.h>

extern "C" void func_020c3aac(unsigned short);

struct GlobalBlock2111224_020c46c8 {
    unsigned short field0;
    unsigned char pad[0x14];
    unsigned short field0x16;
};
extern struct GlobalBlock2111224_020c46c8 data_02111224;

#pragma optimize_for_size off
// USA: func_020c46c8
ARM void SetSubBgExtPaletteFieldAndDispatch020c46c8(unsigned short value) {
    data_02111224.field0 = ~value & (data_02111224.field0 | data_02111224.field0x16);
    data_02111224.field0x16 = value;
    if (value != 0) {
        if (value == 0x80) {
            *(volatile unsigned int*)0x4001000 |= 0x40000000;
            *(volatile unsigned char*)0x4000248 = 0x82;
        }
    } else {
        *(volatile unsigned int*)0x4001000 &= ~0x40000000;
    }
    func_020c3aac(data_02111224.field0);
}
