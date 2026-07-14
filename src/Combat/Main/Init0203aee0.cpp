#include <globaldefs.h>

int GetSignedField020c39c8(volatile unsigned short* p);

struct Struct_0203aee0 {
    int field0;
    int field4;
    int field8;
    float fieldC;
    unsigned char pad10[4];
    int field14;
    float field18;
    unsigned char pad1c[4];
    int field20;
    unsigned char field24;
    unsigned char field25;
    unsigned char field26;
    unsigned char field27;
    unsigned char field28;
};

// USA: func_0203aee0
ARM void Init0203aee0(struct Struct_0203aee0* obj) {
    obj->field0 = 0;
    obj->field4 = 0;
    obj->field8 = 0;
    obj->field14 = 0;
    obj->field20 = 0;
    obj->field24 = 0;
    obj->field25 = 0;
    obj->field26 = 0;
    obj->field27 = 0;
    obj->field28 = 1;
    obj->fieldC = (float)GetSignedField020c39c8((volatile unsigned short*)0x400006c);
    obj->field18 = (float)GetSignedField020c39c8((volatile unsigned short*)0x400106c);
}
