#include <globaldefs.h>

struct S_a0460 {
    char pad[0x14];
    unsigned int val : 9;
    unsigned int hi : 23;
};

// USA: func_020a0460
ARM void AddClamped9BitField(struct S_a0460* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 500) {
        v = 500;
    }
    p->val = v;
}
