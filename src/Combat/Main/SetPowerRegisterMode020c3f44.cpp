#include <globaldefs.h>

extern "C" void func_020c3aac(int);

struct State02111224_020c3f44 {
    unsigned short field0;   // 0x0
    unsigned char pad[0xc];  // 0x2
    unsigned short fieldE;   // 0xe
};

extern struct State02111224_020c3f44 data_02111224;

#pragma optimize_for_size off

// USA: func_020c3f44
ARM void SetPowerRegisterMode020c3f44(int mode) {
    data_02111224.field0 = (data_02111224.field0 | data_02111224.fieldE) & ~mode;
    data_02111224.fieldE = (unsigned short)mode;

    switch (mode) {
    case 0x10:
        *(volatile unsigned int*)0x4000000 |= 0x40000000;
        *(volatile unsigned char*)0x4000244 = 0x84;
        break;
    case 0x40:
        *(volatile unsigned int*)0x4000000 |= 0x40000000;
        *(volatile unsigned char*)0x4000246 = 0x8c;
        break;
    case 0x60:
        *(volatile unsigned char*)0x4000246 = 0x8c;
        // fallthrough
    case 0x20:
        *(volatile unsigned char*)0x4000245 = 0x84;
        *(volatile unsigned int*)0x4000000 |= 0x40000000;
        break;
    case 0:
        *(volatile unsigned int*)0x4000000 &= ~0x40000000;
        break;
    default:
        break;
    }

    func_020c3aac(data_02111224.field0);
}
