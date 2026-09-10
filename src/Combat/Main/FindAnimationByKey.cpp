#include <globaldefs.h>

struct Elem0205a3d0 {
    char unk0[8];
    unsigned short key;
    char unk2[0x18 - 0xa];
};

struct Container0205a3d0 {
    struct Elem0205a3d0* entries;
    unsigned short count;
};

// Looks one entry out of the cell-animation table up by its 16-bit key. The RNAN branch of the
// loader at 0x0205a528 -- NANR, the Nitro animation resource -- stores its entries pointer and count
// into exactly this container, so the table is the animation table itself; the wrappers agree, with
// StartAnimationByKey at 0x0205a370, the stop variant at 0x0205a3ac, func_020e27ec and the
// byte-0x14 setter, though those names come from this same naming pass. Entries are 0x18 bytes: key
// at +8, screen position at +4/+6, current frame index at +0x10, state flags at +0x15.
extern "C" ARM struct Elem0205a3d0* FindAnimationByKey(struct Container0205a3d0* c, int key) {
    struct Elem0205a3d0* result;
    unsigned short i;
    if (c->entries == NULL) {
        return NULL;
    }
    if (c->count == 0) {
        return NULL;
    }
    result = NULL;
    for (i = 0; i < c->count; i++) {
        if (key == c->entries[i].key) {
            result = &c->entries[i];
            break;
        }
    }
    return result;
}
