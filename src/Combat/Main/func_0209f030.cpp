#include <globaldefs.h>
#include "std_library_functions.h"

struct FilterEntry0209f030 {
    unsigned char unk0[0x16];
    unsigned short key;
    unsigned char unk18[0x28];
};

struct FilterEntryList0209f030 {
    int count;
    FilterEntry0209f030 entries[16];
};

struct FilterOwner0209f030 {
    unsigned char unk0[4];
    unsigned char* data;
    unsigned char unk8[0x90];
    FilterEntryList0209f030 kept;
    FilterEntryList0209f030 scratch;
};

// USA: func_0209f030  (semantic: FilterEntriesByKey0209f030)
extern "C" ARM void func_0209f030(struct FilterOwner0209f030* owner, int refilter, int key, int keepAtOrAbove)
{
    if (refilter == 0) {
        int total;
        owner->kept.count = 0;
        total = *(owner->data + 0x8e07);
        for (int i = 0; i < total; i++) {
            FilterEntry0209f030* e = (FilterEntry0209f030*)(owner->data + 0x5c60) + i;
            unsigned short v;
            int n;
            if (e == NULL) {
                continue;
            }
            v = e->key;
            if (keepAtOrAbove != 0) {
                if (v < key) {
                    continue;
                }
            } else {
                if (v >= key) {
                    continue;
                }
            }
            n = owner->kept.count;
            owner->kept.count = owner->kept.count + 1;
            memcpy(&owner->kept.entries[n], e, 0x40);
        }
        return;
    }

    owner->scratch.count = 0;
    memset(owner->scratch.entries, 0, 0x400);
    for (int i = 0; i < owner->kept.count; i++) {
        FilterEntry0209f030* e = &owner->kept.entries[i];
        unsigned short v = e->key;
        int n;
        if (keepAtOrAbove != 0) {
            if (v < key) {
                continue;
            }
        } else {
            if (v >= key) {
                continue;
            }
        }
        n = owner->scratch.count;
        owner->scratch.count = owner->scratch.count + 1;
        memcpy(&owner->scratch.entries[n], e, 0x40);
    }
    owner->kept.count = owner->scratch.count;
    memcpy(owner->kept.entries, owner->scratch.entries, 0x400);
}
