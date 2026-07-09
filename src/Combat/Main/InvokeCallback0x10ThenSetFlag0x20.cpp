#include <globaldefs.h>

struct InvokeCallback0x10ThenSetFlag0x20Obj {
    char pad0[0x8];
    unsigned int flags;
    char padc[0x4];
    void (*cb)(struct InvokeCallback0x10ThenSetFlag0x20Obj*);
};

// USA: func_020b4370
ARM void InvokeCallback0x10ThenSetFlag0x20(struct InvokeCallback0x10ThenSetFlag0x20Obj* obj) {
    if (obj->cb) obj->cb(obj);
    obj->flags |= 0x20;
}
