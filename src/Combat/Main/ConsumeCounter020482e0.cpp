#include <globaldefs.h>

struct Sub130_020482e0 {
    unsigned int flags;
    unsigned short count;
};

struct Combatant020482e0 {
    char pad[0x130];
    struct Sub130_020482e0* sub;
};

// USA: func_020482e0
ARM int ConsumeCounter020482e0(struct Combatant020482e0* c, int amount, int force) {
    struct Sub130_020482e0* sub = c->sub;
    unsigned short count = sub->count;
    if (count <= amount) {
        if (force == 0) {
            sub->count = 1;
            return count - 1;
        }
        sub->count = 0;
        int hadBit4 = 0;
        if (c->sub->flags & 4) {
            hadBit4 = 1;
        }
        c->sub->flags = 1;
        if (hadBit4) {
            c->sub->flags |= 4;
        }
        return count;
    }
    sub->count = count - amount;
    return amount;
}
