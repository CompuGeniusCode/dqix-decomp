#include <globaldefs.h>

struct StatStageStruct02087b3c {
    char pad14[0x14];
    unsigned int flags;
    char pad18[0x40];
    int stage0 : 3;
    int stage3 : 3;
    int stage6 : 3;
    int stage9 : 3;
    int stage12 : 3;
};

// USA: func_02087b3c
ARM int CanAdjustStatStageBit12(struct StatStageStruct02087b3c* p, int decrease) {
    if (p->flags & 1) return 0;
    if (decrease == 0) {
        if (p->stage12 < 2) return 1;
    } else {
        if (p->stage12 > -2) return 1;
    }
    return 0;
}
