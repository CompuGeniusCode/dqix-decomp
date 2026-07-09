#include <globaldefs.h>

struct FindEntry02086e50 {
    signed char id : 6;
    char rest[0x23c - 1];
};

struct FindEntryContainer02086e50 {
    char pad0[0xf80];
    struct FindEntry02086e50 elems[13];
    unsigned char count;
};

// USA: func_02086e50
ARM struct FindEntry02086e50* FindEntryBySignedId02086e50(struct FindEntryContainer02086e50* c, int id) {
    unsigned char i;
    for (i = 0; i < c->count; i++) {
        struct FindEntry02086e50* e = &c->elems[i];
        if (id == e->id) {
            return e;
        }
    }
    return NULL;
}
