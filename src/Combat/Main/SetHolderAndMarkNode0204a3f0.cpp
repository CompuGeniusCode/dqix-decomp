#include <globaldefs.h>

extern "C" void func_02037bbc(void* p);

struct SNode0204a3f0 {
    unsigned int flags0;
    char pad4[0xa4];
    signed int bit0 : 1;
};

struct Holder0204a3f0 {
    char pad0[0x8];
    struct SNode0204a3f0* node;
};

struct Owner0204a3f0 {
    char pad0[0x21c];
    struct Holder0204a3f0* holder;
};

// USA: func_0204a3f0
ARM void SetHolderAndMarkNode0204a3f0(struct Owner0204a3f0* owner, struct Holder0204a3f0* h) {
    struct SNode0204a3f0* s;
    owner->holder = h;
    func_02037bbc(h);
    s = owner->holder->node;
    if (s == NULL) return;
    s = s->bit0 ? s : NULL;
    if (s != NULL) {
        s->flags0 |= 4;
    }
}
