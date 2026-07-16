#include <globaldefs.h>

int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
extern unsigned short data_02114e30;

struct StructC28 {
    char pad0[0x44];
    short* field44;
    char pad48[0x38f - 0x48];
    unsigned char field38f;
    unsigned char field390;
};

// USA: func_ov006_02158c28
ARM void ClearField44IfSet_02158c28(struct StructC28* obj) {
    if (!TestFlag0SetAndFlag1Clear(&data_02114e30, 0x800)) {
        return;
    }
    if (obj->field44 != 0) {
        *obj->field44 = -1;
    }
    obj->field44 = 0;
    obj->field38f = 0xc;
    obj->field390 = 0;
}
