#include <globaldefs.h>

struct TargetInfo_021e1de8 {
    char pad0[8];
    unsigned int category : 4;
    unsigned int subId : 5;
};

struct Entry_021e1de8 {
    int a;
    struct TargetInfo_021e1de8* b;
    short c;
    unsigned short d;
    unsigned short e;
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char rest : 6;
    unsigned char f;
};

struct List_021e1de8 {
    char pad0[4];
    struct Entry_021e1de8* entries;
    short count;
};

// USA: func_ov023_021e1de8  (semantic: CountEntries_021e1de8)
extern "C" ARM short func_ov023_021e1de8(struct List_021e1de8* list, int mode, int arg2, int arg3) {
    short count = list->count;
    short total = 0;
    switch (mode) {
    case 0: {
        for (short cat = 0; cat <= 7; cat++) {
            total = total + func_ov023_021e1de8(list, -1, cat, -1);
        }
        return total;
    }
    case 1:
    case 2:
    default: {
        struct Entry_021e1de8* entries = list->entries;
        for (short i = 0; i < count; i++) {
            struct Entry_021e1de8* cur = &entries[i];
            if (cur->bit1 && cur->b != 0) {
                if (arg2 >= 0 && arg3 >= 0) {
                    if (cur->b->category == arg2 && cur->b->subId == arg3) {
                        total = total + 1;
                    }
                } else if (arg2 >= 0) {
                    if (cur->b->category == arg2) {
                        total = total + 1;
                    }
                } else if (arg3 >= 0) {
                    if (cur->b->subId == arg3) {
                        total = total + 1;
                    }
                }
            }
        }
        return total;
    }
    }
}
