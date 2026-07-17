#include <globaldefs.h>

extern "C" void func_01ff8000(void);

struct LockObj_0220f2e0 {
    int pad0;
    int pad4;
    int owner8;
    int count0xc;
};

#pragma optimize_for_size off

// USA: func_ov031_0220f2e0
ARM int TryLock_0220f2e0(struct LockObj_0220f2e0 *obj) {
    if (obj->owner8 == 0) {
        obj->owner8 = (int)func_01ff8000;
        obj->count0xc = obj->count0xc + 1;
        return 1;
    }
    if (obj->owner8 != (int)func_01ff8000) {
        return 0;
    }
    obj->count0xc = obj->count0xc + 1;
    return 1;
}
