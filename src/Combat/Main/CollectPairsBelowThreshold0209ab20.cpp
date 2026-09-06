#include <globaldefs.h>

struct Pair0209ab20 { unsigned short a; unsigned short b; };
struct SlotElem0209ab20 {
    unsigned char pad0[0xc];
    struct Pair0209ab20 pairs[17];
};
struct Base0209ab20 {
    unsigned char pad100[0x100];
    struct SlotElem0209ab20 slots[13];
    unsigned char pad510[0xc];
    int counts[16];
};
struct Holder0209ab20 {
    struct Base0209ab20* base;
};

// USA: func_0209ab20
ARM int CollectPairsBelowThreshold0209ab20(struct Holder0209ab20* h, int slot, int threshold, unsigned char* out) {
    int idx;
    int count = 0;
    for (idx = 0; idx < h->base->counts[slot]; idx++) {
        unsigned short b = h->base->slots[slot].pairs[idx].b;
        unsigned short a = h->base->slots[slot].pairs[idx].a;
        if (b <= threshold) {
            out[count] = (unsigned char)a;
            count++;
        }
    }
    return count;
}
