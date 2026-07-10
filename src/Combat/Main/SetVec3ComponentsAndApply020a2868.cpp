#include <globaldefs.h>

extern "C" void func_0202e9a4(void*, int);
void ApplyVec3Tail(void*, int*);

struct Struct020a2868 {
    unsigned char pad[0x220];
    int vec[3];    // 0x220, 0x224, 0x228
};

// USA: func_020a2868
ARM void SetVec3ComponentsAndApply020a2868(struct Struct020a2868* obj) {
    obj->vec[1] = 0xc666;
    obj->vec[2] = 0xe666;
    ApplyVec3Tail(obj, obj->vec);
    func_0202e9a4(obj, 0x19000);
}
