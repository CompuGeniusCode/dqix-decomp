#include <globaldefs.h>

struct Elem0207c1ec {
    unsigned char tag : 5;
    unsigned char rest : 3;
    unsigned char pad[3];
};

struct Container0207c1ec {
    struct Elem0207c1ec* elems;
    unsigned short pad4;
    unsigned short count;
};

// USA: func_0207c1ec
ARM int CollectByTag0207c1ec(struct Container0207c1ec* s, int key, struct Elem0207c1ec** out, int max) {
    int found = 0;
    int i = 0;
    while (i < s->count) {
        if (key == s->elems[i].tag) {
            out[found++] = &s->elems[i];
            if (max <= found) return found;
        }
        i++;
    }
    return found;
}
