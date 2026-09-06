#include <globaldefs.h>

struct Entry0202811c {
    unsigned short a;
    unsigned short b;
};

struct Struct0202811c {
    char pad[0x20];
    int result;
    char pad2[1];
    unsigned char count;
    char pad3[2];
    struct Entry0202811c* entries;
};

// USA: func_0202811c
ARM void CheckAllPairsEqual0202811c(struct Struct0202811c* s) {
    int i;
    struct Entry0202811c* entries;
    s->result = 1;
    entries = s->entries;
    if (entries == NULL) return;
    for (i = 0; i < s->count; i++) {
        struct Entry0202811c* e = &entries[i];
        if (e->a != e->b) {
            s->result = 0;
            return;
        }
    }
}
