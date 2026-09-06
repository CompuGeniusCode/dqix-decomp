#include <globaldefs.h>

struct S_02010124 {
    char unk[0x3b4];
    int field3b4;
    int field3b8;
    unsigned short field3bc;
    char pad[2];
    int field3c0;
    int field3c4;
};

// USA: func_02010124
ARM void InitFields02010124(struct S_02010124* obj) {
    obj->field3b4 = 0x21;
    obj->field3b8 = 0x21;
    obj->field3bc = 0x1000;
    obj->field3c4 = 2;
    obj->field3c0 = 0x2000;
}
