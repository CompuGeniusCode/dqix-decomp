#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_02056b48(void* p);

struct Obj02056d10 {
    unsigned char pad_c[0xc];
    unsigned char field_c;
    unsigned char pad_28[0x28 - 0xd];
    unsigned int f28;
    unsigned int f2c;
    unsigned int f30;
    unsigned int f34;
    unsigned char pad_39[0x39 - 0x38];
    unsigned char f39;
    unsigned char f3a;
    unsigned char f3b;
    unsigned char pad_40[0x40 - 0x3c];
    unsigned int f40;
    unsigned int f44;
    unsigned int f48;
    unsigned char pad_c4[0xc4 - 0x4c];
    unsigned char blockA[0xc];
    unsigned char blockB[0xc];
    unsigned char blockC[0xc];
    unsigned char pad_154[0x154 - 0xe8];
    unsigned int f154;
};

// USA: func_02056d10
ARM void ResetObj02056d10(struct Obj02056d10* obj) {
    func_02056b48(obj);
    obj->f30 = 0;
    obj->f2c = 0;
    obj->f28 = 0;
    obj->field_c = 0;
    obj->f39 = 0;
    obj->f3a = 0;
    obj->f3b = 0;
    obj->f40 = 0;
    obj->f44 = 0;
    obj->f48 = 0;
    obj->f154 = 0;
    obj->f34 = 0;
    memset(obj->blockA, 0, 0xc);
    memset(obj->blockB, 0, 0xc);
    memset(obj->blockC, 0, 0xc);
}
