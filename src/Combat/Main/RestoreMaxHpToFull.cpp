#include <globaldefs.h>

struct CurrentStats02048260 {
    unsigned short pad0;
    unsigned short pad2;
    unsigned short value;
};

struct BaseStats02048260 {
    char pad[0x30];
    unsigned short cap;
};

struct Combatant02048260 {
    char pad[0x130];
    struct CurrentStats02048260* current;
    struct BaseStats02048260* base;
};

// USA: func_02048260
ARM int RestoreMaxHpToFull(struct Combatant02048260* c) {
    struct CurrentStats02048260* current = c->current;
    struct BaseStats02048260* base = c->base;
    unsigned short v = current->value;
    unsigned short cap = base->cap;
    if (cap - v <= 0) {
        return 0;
    }
    current->value = cap;
    return cap - v;
}
