#include <globaldefs.h>

extern "C" void func_020c3aac(unsigned short);

struct GlobalBlock2111224_020c4658 {
    unsigned short field0;
    unsigned char pad[0x12];
    unsigned short field0x14;
};
extern struct GlobalBlock2111224_020c4658 data_02111224;

// USA: func_020c4658
ARM void SetVramFieldAndDispatch020c4658(unsigned short value) {
    data_02111224.field0 = ~value & (data_02111224.field0 | data_02111224.field0x14);
    data_02111224.field0x14 = value;
    if (value != 0) {
        switch (value) {
        case 8:
            *(volatile unsigned char*)0x4000243 = 0x84;
            break;
        case 0x100:
            *(volatile unsigned char*)0x4000249 = 0x82;
            break;
        }
    }
    func_020c3aac(data_02111224.field0);
}
