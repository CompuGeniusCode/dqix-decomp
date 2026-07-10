#include <globaldefs.h>

extern "C" void func_0202e9a4(void*, int);
void ApplyVec3Tail(void*, int*);

struct Struct020a27cc {
    unsigned char pad[0x220];
    int vec[3];    // 0x220, 0x224, 0x228
};

// USA: func_020a27cc
ARM void SetVec3ComponentsAndApply020a27cc(struct Struct020a27cc* obj) {
    obj->vec[1] = 0x7999;
    obj->vec[2] = 0xe000;
    ApplyVec3Tail(obj, obj->vec);
    func_0202e9a4(obj, 0xf000);
}
