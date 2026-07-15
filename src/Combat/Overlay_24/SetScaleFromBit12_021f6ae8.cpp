#include <globaldefs.h>

struct Sub_021f6ae8 {
    char unk[0xa];
    unsigned short low12 : 12;
    unsigned short bit12 : 1;
    unsigned short high3 : 3;
};

struct Obj_021f6ae8 {
    char unk0[8];
    struct Sub_021f6ae8* sub;
    char unk1[0x10];
    float f1c;
    float f20;
};

// USA: func_ov024_021f6ae8
ARM int SetScaleFromBit12_021f6ae8(struct Obj_021f6ae8* obj) {
    struct Sub_021f6ae8* sub = obj->sub;
    if (sub != NULL && sub->bit12) {
        obj->f1c = 2.0f;
        obj->f20 = 1.0f;
    } else {
        obj->f1c = 0.0f;
        obj->f20 = 0.0f;
    }
    return 1;
}
