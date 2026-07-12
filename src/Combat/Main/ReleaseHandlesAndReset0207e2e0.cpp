#include <globaldefs.h>
void ResetTimersAndBuffers0207e264(unsigned char*);

int EncodeStreamValue020dc1e8(int);

struct Obj0207e2e0 {
    char pad[0xa4];
    short field_a4;   // 0xa4
    short field_a6;   // 0xa6
};


// USA: func_0207e2e0
ARM void ReleaseHandlesAndReset0207e2e0(struct Obj0207e2e0* obj) {
    EncodeStreamValue020dc1e8(obj->field_a6);
    EncodeStreamValue020dc1e8(obj->field_a4);
    ResetTimersAndBuffers0207e264((unsigned char*)(obj));
}
