#include <globaldefs.h>

struct Entry0207218c {
    char pad0[0x10];
    unsigned int pad10 : 21;
    unsigned int active : 1;
    unsigned int pad10b : 10;
    short pad14;
    short field16;
    short field18;
};

struct Container0207218c {
    char pad0[4];
    struct Entry0207218c* array;
    char pad8[2];
    unsigned short count;
};

// USA: func_0207218c
ARM struct Entry0207218c* FindBestEntryAboveLimit(struct Container0207218c* c, int limit) {
    unsigned short count = c->count;
    struct Entry0207218c* arr = c->array;
    struct Entry0207218c* best = NULL;
    int bestVal = 0x7fff;
    unsigned short i = 0;
    for (; i < count; i++) {
        struct Entry0207218c* e = (struct Entry0207218c*)((char*)arr + (i << 5));
        if (e->active) {
            if (e->field18 > limit && bestVal > e->field18) {
                if (e->field16 <= 0) {
                    bestVal = e->field18;
                    best = e;
                }
            }
        }
    }
    return best;
}
