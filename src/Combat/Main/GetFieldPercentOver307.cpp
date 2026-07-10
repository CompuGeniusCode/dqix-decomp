#include <globaldefs.h>

struct S_a0870 {
    char pad[0x14];
    unsigned int val : 9;
    unsigned int hi : 23;
};

// USA: func_020a0870
ARM int GetFieldPercentOver307(struct S_a0870* p) {
    unsigned int v = p->val;
    unsigned int pct = v * 100 / 307;
    if (pct != 0) {
        return pct;
    }
    if (v != 0) {
        return 1;
    }
    return pct;
}
