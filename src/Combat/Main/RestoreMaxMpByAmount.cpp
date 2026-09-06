#include <globaldefs.h>

struct CurrentStats02048284 {
    unsigned short pad0;
    unsigned short pad2;
    unsigned short pad4;
    unsigned short value;
};

struct BaseStats02048284 {
    char pad[0x32];
    unsigned short cap;
};

struct Combatant02048284 {
    char pad[0x130];
    struct CurrentStats02048284* current;
    struct BaseStats02048284* base;
};

// USA: func_02048284
ARM int RestoreMaxMpByAmount(struct Combatant02048284* c, int amount) {
    struct CurrentStats02048284* current = c->current;
    struct BaseStats02048284* base = c->base;
    int diff = base->cap - current->value;
    if (diff <= 0) {
        return 0;
    }
    if (diff <= amount) {
        current->value = base->cap;
        return diff;
    }
    current->value = current->value + amount;
    return amount;
}
