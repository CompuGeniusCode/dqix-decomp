#include <globaldefs.h>

struct ClearTarget0205a234 {
    int field0;
    unsigned short field4;
};

// Zeroes the {entry pointer, u16 count at +0x4} container that FindAnimationByKey,
// StartAnimationByKey and func_0205a330 all walk -- Overlay_3 hands the same obj+0xd4 to each.
// Callers allocate exactly eight bytes for it, so this is the empty-list initialiser at
// construction, not a teardown of a populated list. The surrounding module loads Nitro 2D
// resources, dispatching at 0x0205a528 on RECN, RNAN, RGCN and RLCN -- NCER, NANR, NCGR and NCLR
// reversed -- so the entries are cell animations. A byte-identical copy sits at 0x0205a244.
extern "C" ARM void ClearAnimationEntryList(struct ClearTarget0205a234* target) {
    target->field0 = 0;
    target->field4 = 0;
}
