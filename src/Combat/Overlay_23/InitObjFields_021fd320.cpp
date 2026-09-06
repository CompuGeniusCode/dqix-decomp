#include <globaldefs.h>

struct Obj_021fd320 {
    char pad0[0x4];
    unsigned short f4;
    unsigned short f6;
    unsigned short f8;
    char pad1[0x1c - 0xa];
    int f1c;
    unsigned short f20;
    unsigned short f22;
    unsigned short f24;
    unsigned short f26;
    unsigned short f28;
    unsigned short f2a;
    unsigned char f2c;
};

extern "C" void func_ov023_021f6ed8(void*);

// USA: func_ov023_021fd320  (semantic: InitObjFields_021fd320)
extern "C" ARM int func_ov023_021fd320(struct Obj_021fd320* obj, int unused, int val, int byteVal, int p5, int p6, int p7, int p8, int p9) {
    func_ov023_021f6ed8(obj);
    obj->f4 = 0x13;
    obj->f6 = (unsigned short)val;
    obj->f8 = (unsigned short)byteVal;
    obj->f1c = 2;
    obj->f20 = (unsigned short)val;
    obj->f22 = (unsigned short)p5;
    obj->f24 = (unsigned short)p6;
    obj->f26 = (unsigned short)p7;
    obj->f28 = (unsigned short)p8;
    obj->f2a = 0;
    obj->f2c = (unsigned char)p9;
    return 1;
}
