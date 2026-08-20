#include <globaldefs.h>

struct SlotEntry020a171c {
    unsigned int costA : 9;
    unsigned int costB : 9;
    unsigned int costC : 9;
    unsigned int flags : 5;
    unsigned int word4;
    unsigned int word8;
};

struct SlotList020a171c {
    SlotEntry020a171c* entries;
    unsigned short unk4;
    unsigned short count;
    unsigned int word8;
    unsigned char* usedBits;
};

// USA: func_020a171c
extern "C" ARM SlotEntry020a171c* func_020a171c(SlotList020a171c* list, int mode, int useHigh) {
    unsigned short best = 0xffff;
    unsigned short bestIdx = 0;
    int i;

    for (i = 0; i < list->count; i++) {
        SlotEntry020a171c* e;
        unsigned short cur;
        if (list->usedBits[i / 8] & (unsigned char)(1 << (i % 8))) {
            continue;
        }
        e = &list->entries[i];
        cur = 0xffff;
        if (mode == 1) {
            cur = e->costA;
        } else if (mode == 2) {
            if (useHigh == 0) {
                cur = e->costB;
            } else {
                cur = e->costC;
            }
        }
        if (best > cur && cur != 0) {
            bestIdx = i;
            best = cur;
        }
    }

    if (best == 0xffff) {
        return 0;
    }
    list->usedBits[bestIdx / 8] |= (unsigned char)(1 << (bestIdx % 8)) & 0xff;
    return &list->entries[bestIdx];
}
