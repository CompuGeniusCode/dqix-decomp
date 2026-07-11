#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" int func_ov017_0218b5b0(void);

struct Obj0207bcec {
    int field0;
    int field4;
    short field8;
};

struct Globals0207bcec {
    int field0;
    int field4;
    SafeAllocator* field8;
};
extern struct Globals0207bcec data_02108e78;

// USA: func_0207bcec
ARM void ResetAllocatorAndClearState0207bcec(struct Obj0207bcec* p, SafeAllocator* alloc) {
    SafeAllocator* def = (SafeAllocator*)(func_ov017_0218b5b0() + 0x18c);
    data_02108e78.field8 = def;
    if (alloc) {
        alloc->Reset();
    } else {
        def->Reset();
    }
    p->field4 = 0;
    p->field8 = 0;
}
