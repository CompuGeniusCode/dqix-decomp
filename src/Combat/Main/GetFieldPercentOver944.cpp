#include <globaldefs.h>

struct S_a08d8 {
    char pad[0x14];
    unsigned int a : 9;
    unsigned int b : 9;
    unsigned int val : 11;
    unsigned int hi : 3;
};

// USA: func_020a08d8
ARM int GetFieldPercentOver944(struct S_a08d8* p) {
    unsigned int v = p->val;
    unsigned int pct = v * 100 / 944;
    if (pct != 0) {
        return pct;
    }
    if (v != 0) {
        return 1;
    }
    return pct;
}
