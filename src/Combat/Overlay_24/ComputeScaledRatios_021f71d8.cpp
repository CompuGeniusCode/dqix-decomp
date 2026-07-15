#include <globaldefs.h>

struct Struct_021f71d8 {
    char unk0[0xc];
    unsigned short field0xc;
    char unk0xe[0x14 - 0xe];
    float field0x14;
    float field0x18;
    float field0x1c;
    float field0x20;
};

// USA: func_ov024_021f71d8
ARM int ComputeScaledRatios_021f71d8(struct Struct_021f71d8* obj) {
    obj->field0x1c = (4.0f * obj->field0x14) / (float)(obj->field0xc + 1);
    obj->field0x20 = (4.0f * obj->field0x18) / (float)(obj->field0xc + 1);
    return 1;
}
