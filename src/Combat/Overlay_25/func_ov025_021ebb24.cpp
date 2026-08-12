#include <globaldefs.h>

struct ResetEntryStruct_021ebb24 {
    unsigned int f00;
    unsigned char f04 : 6;
    unsigned char f04b : 2;
    unsigned char f05;
    unsigned char f06;
    unsigned char pad07;
    unsigned int f08;
    unsigned int f0c;
    unsigned int f10;
    unsigned int f14;
    unsigned int f18;
    unsigned int f1c;
    short f20;
    short f22;
    unsigned int f24;
    unsigned int f28;
    short f2c;
    short f2e;
    short f30;
    short pad32;
    unsigned char f34pad[4];
    unsigned char f38;
    unsigned char pad39;
    unsigned char f3a;
    unsigned char pad3b;
    short f3c;
};

// USA: func_ov025_021ebb24
extern "C" ARM void func_ov025_021ebb24(struct ResetEntryStruct_021ebb24* obj) {
    obj->f00 = 0;
    obj->f04 = 0;
    obj->f04b = 0;
    obj->f05 = 0;
    obj->f08 = 0;
    obj->f0c = 0;
    obj->f10 = 0;
    obj->f14 = 0;
    obj->f18 = 0;
    obj->f1c = 0;
    obj->f20 = -1;
    obj->f22 = -1;
    obj->f24 = 0;
    obj->f06 = 0;
    obj->f28 = 0;
    obj->f2c = 0;
    obj->f30 = 0;
    obj->f2e = 0;
    obj->f38 = 0;
    obj->f3a = 0;
    obj->f3c = 0;
}
