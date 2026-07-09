#include <globaldefs.h>

struct CurrentStats020482bc {
    unsigned short pad0;
    unsigned short pad2;
    unsigned short pad4;
    unsigned short value;
};

struct BaseStats020482bc {
    char pad[0x32];
    unsigned short cap;
};

struct Combatant020482bc {
    char pad[0x130];
    struct CurrentStats020482bc* current;
    struct BaseStats020482bc* base;
};

// USA: func_020482bc
ARM int RestoreMaxMpToFull(struct Combatant020482bc* c) {
    struct CurrentStats020482bc* current = c->current;
    struct BaseStats020482bc* base = c->base;
    unsigned short v = current->value;
    unsigned short cap = base->cap;
    if (cap - v <= 0) {
        return 0;
    }
    current->value = cap;
    return cap - v;
}
