#include <globaldefs.h>

int EncodeStreamValue020dc1e8(int);
extern "C" int func_020dc184(void* src, int mode);

struct Obj0207ecf8 {
    char pad0[0x58];
    void* field_58;
    char pad1[0x48];
    short field_a4;
};

// USA: func_0207ecf8
ARM void ReacquireHandleField0xa4(struct Obj0207ecf8* obj) {
    EncodeStreamValue020dc1e8(obj->field_a4);
    obj->field_a4 = func_020dc184(obj->field_58, 0);
}
