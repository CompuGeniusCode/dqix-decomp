#include <globaldefs.h>

struct StatStageStruct02087a48 {
    char pad14[0x14];
    unsigned int flags;
    char pad18[0x40];
    int stage0 : 3;
    int stage3 : 3;
    int stage6 : 3;
    int stage9 : 3;
};

// USA: func_02087a48
ARM int CanAdjustStatStageBit9(struct StatStageStruct02087a48* p, int decrease) {
    if (p->flags & 1) return 0;
    if (decrease == 0) {
        if (p->stage9 < 2) return 1;
    } else {
        if (p->stage9 > -2) return 1;
    }
    return 0;
}
