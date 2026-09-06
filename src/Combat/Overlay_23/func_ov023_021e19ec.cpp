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

struct List_021e19ec {
    char pad0[4];
    struct Struct_021e12cc* entries;
    short count;
};

// USA: func_ov023_021e19ec  (semantic: FindBestEntry_021e19ec)
extern "C" ARM struct Struct_021e12cc* func_ov023_021e19ec(struct List_021e19ec* list, int filterMode, int arg2, int arg3, int requireBit1) {
    unsigned short bestVal = 0xffff;
    int ok;
    struct Struct_021e12cc* cur;
    struct Struct_021e12cc* best = 0;
    struct Struct_021e12cc* entries = list->entries;
    short count = list->count;
    for (short i = 0; i < count; i++) {
        cur = &entries[i];
        if (cur->bit0) {
            continue;
        }
        if (bestVal < cur->e) {
            continue;
        }
        if (requireBit1 && !cur->bit1) {
            continue;
        }
        if (filterMode == 0) {
            ok = (cur->rest >= 8 && cur->rest <= 9) ? 1 : 0;
            if (!ok) {
                continue;
            }
        } else {
            if (arg2 >= 0 && arg3 >= 0) {
                if (cur->f == arg3) {
                    if (cur->rest != arg2) {
                        continue;
                    }
                } else {
                    continue;
                }
            } else if (arg2 >= 0) {
                if (cur->rest != arg2) {
                    continue;
                }
            } else if (arg3 >= 0) {
                if (cur->f != arg3) {
                    continue;
                }
            }
        }
        bestVal = cur->e;
        best = cur;
    }
    if (best != 0) {
        best->bit0 = 1;
    }
    return best;
}
