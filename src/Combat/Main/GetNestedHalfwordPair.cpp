#include <globaldefs.h>

struct Inner02059c90 {
    char unk0[0x28];
    unsigned short field28;
    unsigned short field2a;
};

struct Mid02059c90 {
    char unk0[0x54];
    struct Inner02059c90* field54;
};

struct Outer02059c90 {
    char unk0[0x84];
    struct Mid02059c90* field84;
};

// USA: func_02059c90
ARM void GetNestedHalfwordPair(struct Outer02059c90* obj, unsigned short* out0, unsigned short* out1) {
    *out0 = obj->field84->field54->field28;
    *out1 = obj->field84->field54->field2a;
}
