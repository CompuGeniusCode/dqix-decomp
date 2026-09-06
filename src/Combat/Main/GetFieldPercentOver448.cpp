#include <globaldefs.h>

struct S_a090c {
    char pad[0x10];
    unsigned int lo : 23;
    unsigned int val : 9;
};

// USA: func_020a090c
ARM int GetFieldPercentOver448(struct S_a090c* p) {
    unsigned int v = p->val;
    unsigned int pct = v * 100 / 448;
    if (pct != 0) {
        return pct;
    }
    if (v != 0) {
        return 1;
    }
    return pct;
}
