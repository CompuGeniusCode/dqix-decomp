#include <globaldefs.h>
#include "System/ProcessorContext.h"

extern "C" void func_01ff8000(void);

struct LockObj_0220f330 {
    int pad0;
    int pad4;
    int owner8;
    int count0xc;
};

// USA: func_ov031_0220f330
ARM void ReleaseLock_0220f330(struct LockObj_0220f330 *obj) {
    if (obj->owner8 != (int)func_01ff8000) {
        return;
    }
    obj->count0xc = obj->count0xc - 1;
    if (obj->count0xc != 0) {
        return;
    }
    obj->owner8 = 0;
    UnblockContexts((struct BlockedContextList*)obj);
}
