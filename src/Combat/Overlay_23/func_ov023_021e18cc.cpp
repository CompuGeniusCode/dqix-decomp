#include <globaldefs.h>

struct Struct_021e12cc {
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

struct List_021e18cc {
    char pad0[4];
    struct Struct_021e12cc* entries;
    short count;
};

// USA: func_ov023_021e18cc  (semantic: FindBestEntryFiltered_021e18cc)
extern "C" ARM struct Struct_021e12cc* func_ov023_021e18cc(struct List_021e18cc* list, int filterMode, int arg2, int arg3, int requireAvail) {
    unsigned short bestVal = 0xffff;
    struct Struct_021e12cc* e;
    struct Struct_021e12cc* best = 0;
    struct Struct_021e12cc* entries = list->entries;
    short count = list->count;
    for (short i = 0; i < count; i++) {
        e = &entries[i];
        if (e->bit0) {
            continue;
        }
        if (bestVal < e->d) {
            continue;
        }
        if (requireAvail != 0 && !e->bit1) {
            continue;
        }
        if (filterMode == 0) {
            int ok = (e->rest >= 8 && e->rest <= 9) ? 1 : 0;
            if (!ok) {
                continue;
            }
        } else {
            if (arg2 >= 0 && arg3 >= 0) {
                if (e->f == arg3) {
                    if (e->rest != arg2) {
                        continue;
                    }
                } else {
                    continue;
                }
            } else if (arg2 >= 0) {
                if (e->rest != arg2) {
                    continue;
                }
            } else if (arg3 >= 0) {
                if (e->f != arg3) {
                    continue;
                }
            }
        }
        bestVal = e->d;
        best = e;
    }
    if (best != 0) {
        best->bit0 = 1;
    }
    return best;
}
