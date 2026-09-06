#include <globaldefs.h>

struct S02074af4 {
    short field0;
    char pad1[2];
    short field4;
    char pad2[2];
    short field8;
    char pad3[2];
    short fieldC;
    char pad4[2];
    unsigned char flag;
};

// USA: func_02074af4
ARM void SaveBgControlRegs02074af4(struct S02074af4* obj) {
    if (obj->flag != 0) return;
    volatile unsigned short* reg = (volatile unsigned short*)0x4000008;
    volatile short v0 = reg[0];
    v0;
    obj->field0 = v0;
    volatile short v1 = reg[1];
    obj->field4 = v1;
    volatile short v2 = reg[2];
    v2;
    obj->field8 = v2;
    volatile short v3 = reg[3];
    obj->fieldC = v3;
    obj->flag = 1;
}
