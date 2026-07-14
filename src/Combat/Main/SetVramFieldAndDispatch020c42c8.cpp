#include <globaldefs.h>

extern "C" void func_020c3aac(unsigned short);

struct GlobalBlock2111224_020c42c8 {
    unsigned short field0;
    unsigned char pad[8];
    unsigned short field0xa;
};
extern struct GlobalBlock2111224_020c42c8 data_02111224;

// USA: func_020c42c8
#pragma optimize_for_size off
ARM void SetVramFieldAndDispatch020c42c8(int value) {
    data_02111224.field0 = (unsigned short)(~value & (data_02111224.field0 | data_02111224.field0xa));
    data_02111224.field0xa = (unsigned short)value;

    switch (value) {
    case 0x60:
        *(volatile unsigned char*)0x4000246 = 0x8b;
        // fallthrough
    case 0x20:
        *(volatile unsigned char*)0x4000245 = 0x83;
        break;
    case 0x40:
        *(volatile unsigned char*)0x4000246 = 0x83;
        break;
    case 0x70:
        *(volatile unsigned char*)0x4000246 = 0x9b;
        // fallthrough
    case 0x30:
        *(volatile unsigned char*)0x4000245 = 0x93;
        // fallthrough
    case 0x10:
        *(volatile unsigned char*)0x4000244 = 0x83;
        break;
    case 0x00:
    default:
        break;
    }

    func_020c3aac(data_02111224.field0);
}
