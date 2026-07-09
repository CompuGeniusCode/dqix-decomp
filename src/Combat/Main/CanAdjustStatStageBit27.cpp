#include <globaldefs.h>

struct StatStageStruct02087f24 {
    char pad14[0x14];
    unsigned int flags;
    char pad18[0x40];
    int : 27;
    int stage : 3;
};

// USA: func_02087f24
ARM int CanAdjustStatStageBit27(struct StatStageStruct02087f24* p, int decrease) {
    if (p->flags & 1) return 0;
    if (decrease == 0) {
        if (p->stage < 2) return 1;
    } else {
        if (p->stage > -2) return 1;
    }
    return 0;
}
