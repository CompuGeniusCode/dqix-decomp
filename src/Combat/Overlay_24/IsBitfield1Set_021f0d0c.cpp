#include <globaldefs.h>

struct S_bf3c_021f0d0c_inner {
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

struct S_bf3c_021f0d0c {
    char unk[0x138];
    struct S_bf3c_021f0d0c_inner* inner;
};

// USA: func_ov024_021f0d0c
ARM int IsBitfield1Set_021f0d0c(struct S_bf3c_021f0d0c* obj) {
    return obj->inner->b1 != 0;
}
