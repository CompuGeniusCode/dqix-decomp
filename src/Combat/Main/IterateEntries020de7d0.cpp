#include <globaldefs.h>

struct Element020de7d0 {
    unsigned int v[8];
};

struct Container020de7d0 {
    unsigned short count;
    unsigned char pad[10];
    struct Element020de7d0* base;
};

typedef void (*Callback020de7d0)(struct Container020de7d0*, struct Element020de7d0*);

// USA: func_020de7d0
ARM int IterateEntries020de7d0(struct Container020de7d0* c, Callback020de7d0 cb) {
    int count;
    struct Element020de7d0* elem;
    int i;

    elem = c->base;
    if (elem == NULL || (count = c->count) == 0 || cb == NULL) return 0;
    for (i = 0; i < count; i++, elem++) {
        cb(c, elem);
    }
    return 1;
}
