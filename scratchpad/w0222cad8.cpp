#include <globaldefs.h>

struct Inner0222cad8 {
    unsigned char pad[0x38];
    void* field0x38;
    unsigned char pad2[0x40 - 0x38 - 4];
    unsigned short field0x40;
    unsigned char pad3[0x51 - 0x40 - 2];
    unsigned char field0x51;
    unsigned char pad4[0x59 - 0x51 - 1];
    unsigned char field0x59;
};
struct Struct0222cad8 {
    unsigned char pad[2];
    unsigned short field2;
    Inner0222cad8* field4;
};
extern Struct0222cad8 data_ov031_02290c8c;
extern "C" int func_ov031_02236878(int index);
extern void* CallWithZeroExtra_0223e218(void* a, void* b, void* c, int d);
extern "C" void func_ov031_0222c7d8(void);

// USA: func_ov031_0222cad8
extern "C" ARM void func_ov031_0222cad8(void) {
    Inner0222cad8* inner = data_ov031_02290c8c.field4;
    if (data_ov031_02290c8c.field2 == inner->field0x40 || inner->field0x51 <= 4) {
        if (inner->field0x59 != 0) return;
        func_ov031_02236878(9);
        data_ov031_02290c8c.field4->field0x59 = 1;
    } else {
        func_ov031_02236878(0x13);
        void* r = CallWithZeroExtra_0223e218(NULL, (void*)func_ov031_0222c7d8, NULL, 0x78);
        data_ov031_02290c8c.field4->field0x38 = r;
    }
}
