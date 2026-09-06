#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_ov008_02187b20(void*, void*, int);
extern "C" void func_0205d304(void*, void*, int, int, int, int, int, int);

struct S02187a70 {
    char pad0[0xb8];
    void* buf;
    char pad1[0x1d0 - 0xbc];
    unsigned short a0;
    unsigned short a1;
    unsigned short a2;
    unsigned short a3;
    unsigned short a4;
    unsigned short a5;
    unsigned short a6;
    unsigned short a7;
    char pad2[0x1e1 - 0x1e0];
    unsigned char b1;
    char pad3[0x1e5 - 0x1e2];
    unsigned char b2;
    unsigned char b3;
    unsigned char b4;
};

// USA: func_02187a70
ARM void InitBattleData_02187a70(struct S02187a70* obj, int arg2) {
    obj->a0 = 0x12;
    obj->a1 = 0xb;
    obj->a2 = 0xd;
    obj->a3 = 0x3;
    obj->a4 = 0x2;
    obj->a5 = 0x1;
    obj->a6 = 0xa;
    obj->a7 = 0xf;
    obj->b4 = 0xa;
    obj->b1 = 0x3;
    obj->b2 = 0x1;
    obj->b3 = 0x1;
    memset(obj->buf, 0, 0x960);
    func_ov008_02187b20(obj, obj->buf, arg2);
    func_0205d304((char*)obj + 0x130, obj->buf, 0, 0, 0, 0, 0, 0);
}
