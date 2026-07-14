#include <globaldefs.h>

extern "C" void func_020c3aac(int);

struct State02111224_020c3df4 {
    unsigned short field0;   // 0x0
    unsigned char pad[2];
    unsigned short field4;   // 0x4
};

extern struct State02111224_020c3df4 data_02111224;

// USA: func_020c3df4
ARM void SetVramBankAndDispatch020c3df4(int mode) {
    data_02111224.field0 = (unsigned short)(~mode & (data_02111224.field0 | data_02111224.field4));
    data_02111224.field4 = (unsigned short)mode;

    switch (mode) {
    case 3:
        *(volatile unsigned char*)0x4000241 = 0x8a;
        // fallthrough
    case 1:
        *(volatile unsigned char*)0x4000240 = 0x82;
        break;
    case 2:
        *(volatile unsigned char*)0x4000241 = 0x82;
        break;
    case 0x70:
        *(volatile unsigned char*)0x4000246 = 0x9a;
        // fallthrough
    case 0x30:
        *(volatile unsigned char*)0x4000245 = 0x92;
        // fallthrough
    case 0x10:
        *(volatile unsigned char*)0x4000244 = 0x82;
        break;
    case 0x40:
        *(volatile unsigned char*)0x4000246 = 0x82;
        break;
    case 0x50:
        *(volatile unsigned char*)0x4000246 = 0x92;
        *(volatile unsigned char*)0x4000244 = 0x82;
        break;
    case 0x60:
        *(volatile unsigned char*)0x4000246 = 0x8a;
        // fallthrough
    case 0x20:
        *(volatile unsigned char*)0x4000245 = 0x82;
        break;
    case 0:
    default:
        break;
    }

    func_020c3aac(data_02111224.field0);
}
