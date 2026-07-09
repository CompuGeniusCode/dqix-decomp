#include <globaldefs.h>

struct CurrentStats02048228 {
    unsigned short pad0;
    unsigned short pad2;
    unsigned short value;
};

struct BaseStats02048228 {
    char pad[0x30];
    unsigned short cap;
};

struct Combatant02048228 {
    char pad[0x130];
    struct CurrentStats02048228* current;
    struct BaseStats02048228* base;
};

// USA: func_02048228
ARM int RestoreMaxHpByAmount(struct Combatant02048228* c, int amount) {
    struct CurrentStats02048228* current = c->current;
    struct BaseStats02048228* base = c->base;
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
