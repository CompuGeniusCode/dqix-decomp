#include <globaldefs.h>

extern "C" void func_020c3aac(unsigned short);

struct GlobalBlock2111224_020c4748 {
    unsigned short field0;
    unsigned char pad[0x16];
    unsigned short field0x18;
};
extern struct GlobalBlock2111224_020c4748 data_02111224;

#pragma optimize_for_size off
// USA: func_020c4748
ARM void SetSubObjExtPaletteFieldAndDispatch020c4748(unsigned short value) {
    data_02111224.field0 = ~value & (data_02111224.field0 | data_02111224.field0x18);
    data_02111224.field0x18 = value;
    if (value != 0) {
        if (value == 0x100) {
            *(volatile unsigned int*)0x4001000 |= 0x80000000;
            *(volatile unsigned char*)0x4000249 = 0x83;
        }
    } else {
        *(volatile unsigned int*)0x4001000 &= ~0x80000000;
    }
    func_020c3aac(data_02111224.field0);
}
