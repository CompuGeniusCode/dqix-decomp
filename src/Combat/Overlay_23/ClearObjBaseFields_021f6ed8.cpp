#include <globaldefs.h>

struct ObjBase021f6ed8 {
    char pad0[4];
    unsigned short f4;
    unsigned short f6;
    unsigned short f8;
    char pad_a[2];
    unsigned char fc;
    unsigned int f10;
    unsigned int f14;
    unsigned int f18;
    unsigned int f1c;
};

// USA: func_ov023_021f6ed8  (semantic: ClearObjBaseFields_021f6ed8)
extern "C" ARM void func_ov023_021f6ed8(ObjBase021f6ed8* obj) {
    obj->f4 = 0xffff;
    obj->f6 = 0;
    obj->f8 = 0;
    obj->f10 = 0;
    obj->f14 = 0;
    obj->f18 = 0;
    obj->fc = 0;
    obj->f1c = 0;
}
