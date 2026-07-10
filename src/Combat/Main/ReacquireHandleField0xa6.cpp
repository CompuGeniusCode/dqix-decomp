#include <globaldefs.h>

int EncodeStreamValue020dc1e8(int);
extern "C" int func_020dc124(void* src, int mode);

struct Obj0207ecd4 {
    char pad0[0x58];
    void* field_58;
    char pad1[0x4a];
    short field_a6;
};

// USA: func_0207ecd4
ARM void ReacquireHandleField0xa6(struct Obj0207ecd4* obj) {
    EncodeStreamValue020dc1e8(obj->field_a6);
    obj->field_a6 = func_020dc124(obj->field_58, 0);
}
