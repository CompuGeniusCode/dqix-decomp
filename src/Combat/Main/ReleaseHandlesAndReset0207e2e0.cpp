#include <globaldefs.h>

int EncodeStreamValue020dc1e8(int);

struct Obj0207e2e0 {
    char pad[0xa4];
    short field_a4;   // 0xa4
    short field_a6;   // 0xa6
};

extern "C" void func_0207e264(struct Obj0207e2e0* obj);

// USA: func_0207e2e0
ARM void ReleaseHandlesAndReset0207e2e0(struct Obj0207e2e0* obj) {
    EncodeStreamValue020dc1e8(obj->field_a6);
    EncodeStreamValue020dc1e8(obj->field_a4);
    func_0207e264(obj);
}
