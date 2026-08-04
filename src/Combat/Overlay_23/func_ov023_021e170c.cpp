#include <globaldefs.h>

struct Entry_021e170c {
    int a;
    int b;
    short c;
    unsigned short d;
    unsigned short e;
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char rest : 6;
    unsigned char f;
};

struct List_021e170c {
    char pad0[4];
    struct Entry_021e170c* entries;
    short count;
    short capacity;
};

// USA: func_ov023_021e170c
extern "C" ARM struct Entry_021e170c* func_ov023_021e170c(struct List_021e170c* list, int mode, int type, int variant) {
    unsigned short threshold = 0xffff;
    struct Entry_021e170c* e;
    struct Entry_021e170c* best = 0;
    struct Entry_021e170c* entries = list->entries;
    short count = list->count;
    for (short i = 0; i < count; i++) {
        e = &entries[i];
        if (e->bit0) continue;
        if (threshold < e->e) continue;
        if (!e->bit1) continue;
        if (mode == 0) {
            int ok = e->rest <= 7;
            if (!ok) continue;
        } else if (type >= 0 && variant >= 0) {
            if (e->f != variant) continue;
            if (!(e->rest == type)) continue;
        } else if (type >= 0) {
            if (e->rest != type) continue;
        } else if (variant >= 0) {
            if (e->f != variant) continue;
        }
        threshold = e->e;
        best = e;
    }
    if (best) {
        best->bit0 = 1;
    }
    return best;
}
