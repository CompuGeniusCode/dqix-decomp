#include <globaldefs.h>

extern "C" void func_ov031_02236878(int);
extern "C" void func_ov031_0222c7d8(void);
void* CallWithZeroExtra_0223e218(void*, void*, void*, int);

struct CombatantCtx0222cad8 {
    unsigned char pad0[0x38];
    int field38;
    unsigned char pad3c[4];
    unsigned short field40;
    unsigned char pad42[15];
    unsigned char field51;
    unsigned char pad52[7];
    unsigned char field59;
};

struct Context0222cad8 {
    short pad0;
    unsigned short field2;
    CombatantCtx0222cad8* field4;
};
extern Context0222cad8 data_ov031_02290c8c;

// USA: func_ov031_0222cad8
extern "C" ARM void func_ov031_0222cad8(void) {
    CombatantCtx0222cad8* c = data_ov031_02290c8c.field4;
    if (data_ov031_02290c8c.field2 == c->field40 || c->field51 <= 4) {
        if (c->field59 != 0) return;
        func_ov031_02236878(9);
        data_ov031_02290c8c.field4->field59 = 1;
    } else {
        func_ov031_02236878(0x13);
        void* result = CallWithZeroExtra_0223e218((void*)0, (void*)func_ov031_0222c7d8, (void*)0, 0x78);
        data_ov031_02290c8c.field4->field38 = (int)result;
    }
}
