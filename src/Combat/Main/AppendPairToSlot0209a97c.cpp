#include <globaldefs.h>

struct Pair0209a97c { unsigned short a; unsigned short b; };
struct PairArray0209a97c { struct Pair0209a97c pairs[20]; };
struct Base0209a97c {
    unsigned char pad[0x10c];
    struct PairArray0209a97c slotPairs[13];
    int counts[16];
};
struct Holder0209a97c {
    struct Base0209a97c* base;
};

// USA: func_0209a97c
ARM void AppendPairToSlot0209a97c(struct Holder0209a97c* h, int slot, struct Pair0209a97c* src) {
    struct Base0209a97c* b = h->base;
    int count;
    if (b == NULL) return;
    count = b->counts[slot];
    if (count >= 0x14) return;
    b->counts[slot]++;
    {
        struct Pair0209a97c* dst = &h->base->slotPairs[slot].pairs[count];
        dst->a = src->a;
        dst->b = src->b;
    }
}
