#include <globaldefs.h>

struct Entry020429e4 {
    unsigned char k0;
    unsigned char k1;
};

struct Table020429e4 {
    unsigned short stride;
    char pad2[4];
    short count;
    struct Entry020429e4* entries;
    char* data;
};

// USA: func_020429e4
ARM char* FindEntryByKeyPair020429e4(struct Table020429e4* t, unsigned char* key) {
    int count;
    struct Entry020429e4* e;
    int i;
    unsigned char k0, k1;
    if (t == NULL) {
        return NULL;
    }
    if (key == NULL) {
        k0 = 0;
        k1 = 0;
    } else {
        k0 = key[0];
        k1 = key[1];
    }
    count = t->count;
    e = t->entries;
    for (i = 0; i < count; e++, i++) {
        if (k0 == e->k0 && k1 == e->k1) {
            return t->data + i * t->stride;
        }
    }
    return NULL;
}
