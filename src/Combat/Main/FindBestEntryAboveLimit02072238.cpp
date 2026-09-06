#include <globaldefs.h>

struct Entry02072238 {
    char pad0[0x10];
    unsigned int pad10 : 21;
    unsigned int active : 1;
    unsigned int pad10b : 10;
    short pad14;
    short field16;
    short pad18;
    short field1a;
};

struct Container02072238 {
    char pad0[4];
    struct Entry02072238* array;
    char pad8[2];
    unsigned short count;
};

// USA: func_02072238
ARM struct Entry02072238* FindBestEntryAboveLimit02072238(struct Container02072238* c, int limit) {
    unsigned short count = c->count;
    struct Entry02072238* arr = c->array;
    struct Entry02072238* best = NULL;
    int bestVal = 0x7fff;
    unsigned short i = 0;
    for (; i < count; i++) {
        struct Entry02072238* e = (struct Entry02072238*)((char*)arr + (i << 5));
        if (e->active) {
            if (e->field1a > limit && bestVal > e->field1a) {
                if (e->field16 <= 0) {
                    bestVal = e->field1a;
                    best = e;
                }
            }
        }
    }
    return best;
}
