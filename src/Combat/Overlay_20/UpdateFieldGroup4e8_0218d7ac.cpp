#include <globaldefs.h>

void EncodeSignFlaggedHalfword(short* out, int value);
int GetSignedField020c39c8(volatile unsigned short* p);

struct FieldGroup4e8_0218d7ac {
    char pad[0x4e8];
    float f4e8;
    int f4ec;
    int f4f0;
};

// USA: func_ov020_0218d7ac
ARM void UpdateFieldGroup4e8_0218d7ac(struct FieldGroup4e8_0218d7ac* obj, int a1, int a2) {
    if (a2 == 0) {
        EncodeSignFlaggedHalfword((short*)0x400006c, a1);
        obj->f4e8 = (float)a1;
        obj->f4ec = a1;
        obj->f4f0 = 0;
    } else {
        int v = GetSignedField020c39c8((volatile unsigned short*)0x400006c);
        obj->f4e8 = (float)v;
        obj->f4ec = a1;
        obj->f4f0 = a2;
    }
}
