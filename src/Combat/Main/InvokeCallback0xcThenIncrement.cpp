#include <globaldefs.h>

struct InvokeCallback0xcThenIncrementObj {
    int field_0;
    char pad4[0x8];
    void (*cb)(struct InvokeCallback0xcThenIncrementObj*);
};

// USA: func_020b4348
ARM void InvokeCallback0xcThenIncrement(struct InvokeCallback0xcThenIncrementObj* obj) {
    if (obj->cb) obj->cb(obj);
    obj->field_0++;
}
