#include <globaldefs.h>

struct S_a08a4 {
    char pad[0x14];
    unsigned int a : 9;
    unsigned int val : 9;
    unsigned int hi : 14;
};

// USA: func_020a08a4
ARM int GetFieldPercentOver232(struct S_a08a4* p) {
    unsigned int v = p->val;
    unsigned int pct = v * 100 / 232;
    if (pct != 0) {
        return pct;
    }
    if (v != 0) {
        return 1;
    }
    return pct;
}
