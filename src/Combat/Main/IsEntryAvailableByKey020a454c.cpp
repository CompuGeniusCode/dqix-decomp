#include <globaldefs.h>

struct Elem020a454c {
    unsigned short h0;
    unsigned char b2;
    unsigned char b3;
};

struct Struct020a454c {
    unsigned char pad0[0xa];
    unsigned char field0xa;
    unsigned char pad1[0x3b];
    unsigned char count;
    unsigned char pad2;
    struct Elem020a454c arr[1];
};

// USA: func_020a454c
ARM int IsEntryAvailableByKey020a454c(struct Struct020a454c* s, int key) {
    struct Elem020a454c* e;
    int i;
    for (i = 0; i < s->count; i++) {
        e = &s->arr[i];
        if (e->h0 == key) {
            return e->b2 <= s->field0xa;
        }
    }
    return 1;
}
