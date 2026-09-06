#include <globaldefs.h>

struct S_bf3c_021f1440_inner {
    char unk[0x3c];
    unsigned char b0:1;
    unsigned char b1:1;
    unsigned char b2:1;
    unsigned char b3:1;
    unsigned char b4:1;
    unsigned char b5:1;
    unsigned char b6:1;
    unsigned char b7:1;
};

struct S_bf3c_021f1440 {
    char unk[0x138];
    struct S_bf3c_021f1440_inner* inner;
};

// USA: func_ov024_021f1440
ARM int IsBitfield2Set_021f1440(struct S_bf3c_021f1440* obj) {
    return obj->inner->b2 != 0;
}
