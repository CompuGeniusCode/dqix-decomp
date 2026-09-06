#include <globaldefs.h>

#pragma optimize_for_size off

struct SlotData_0221474c {
    unsigned char pad00[0x40];
    unsigned char listA[0x20];
    unsigned char listB[0x20];
    unsigned char pad80[0x67];
    unsigned char kind;
    unsigned char padE8[0x18];
};

struct GroupEntry_0221474c {
    unsigned char f0;
    unsigned char slot;
    unsigned char f2;
    unsigned char count;
    unsigned char items[0x20];
};

struct GroupList_0221474c {
    SlotData_0221474c slots[3];
    GroupEntry_0221474c entries[1];
    unsigned char pad324[0x9e8];
    unsigned char filter : 4;
};

// USA: func_ov031_0221474c  (semantic: CollectSlotItemGroups_0221474c)
extern "C" ARM int func_ov031_0221474c(GroupList_0221474c* list) {
    int i;
    unsigned char count = 0;
    SlotData_0221474c* p = list->slots;
    i = 0;
    GroupEntry_0221474c* out = list->entries;

    do {
        unsigned int filter = list->filter;
        if (filter == 0 || filter == (unsigned int)(i + 1)) {
            if (p->kind != 0xff) {
                unsigned char n = 0;
                bool ok;
                do {
                    unsigned char v = p->listA[n];
                    if (v == 0) {
                        break;
                    }
                    out->items[n] = v;
                    n++;
                } while (n < 0x20);
                if (n != 0) {
                    out->count = n;
                    out->slot = i;
                    ok = true;
                } else {
                    ok = false;
                }
                if (ok) {
                    count++;
                    out++;
                }

                if (p->kind == 1) {
                    unsigned char m = 0;
                    bool ok2;
                    do {
                        unsigned char v = p->listB[m];
                        if (v == 0) {
                            break;
                        }
                        out->items[m] = v;
                        m++;
                    } while (m < 0x20);
                    if (m == 0) {
                        ok2 = false;
                    } else {
                        out->count = m;
                        out->slot = i + 3;
                        ok2 = true;
                    }
                    if (ok2) {
                        count++;
                        out++;
                    }
                }
            }
        }
        i++;
        p++;
    } while (i < 3);
    return count;
}
