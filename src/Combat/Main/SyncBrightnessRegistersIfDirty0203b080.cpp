#include <globaldefs.h>

void EncodeSignFlaggedHalfword(short* out, int value);

struct Brightness0203b080 {
    char pad0[0xc];
    float fieldC;
    char pad1[0x18 - 0xc - 4];
    float field18;
    char pad2[0x26 - 0x18 - 4];
    unsigned char field26;
    unsigned char field27;
    unsigned char field28;
};

// USA: func_0203b080  (semantic: SyncBrightnessRegistersIfDirty0203b080)
extern "C" ARM void func_0203b080(struct Brightness0203b080* obj) {
    if (obj->field28 == 0) return;
    obj->field28 = 0;
    if (obj->field26 != 0) {
        EncodeSignFlaggedHalfword((short*)0x400006c, (int)obj->fieldC);
    }
    obj->field26 = 0;
    if (obj->field27 != 0) {
        EncodeSignFlaggedHalfword((short*)0x400106c, (int)obj->field18);
    }
    obj->field27 = 0;
}
