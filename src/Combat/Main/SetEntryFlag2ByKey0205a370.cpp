#include <globaldefs.h>

struct Elem0205a370 {
    char unk0[0x10];
    unsigned short unk10;
    unsigned short unk12;
    unsigned char unk14;
    unsigned char flags15;
    char unk16[2];
};

struct Container0205a3d0;

extern struct Elem0205a370* FindEntryByHalfword0205a3d0(struct Container0205a3d0*, int);

// USA: func_0205a370
ARM void SetEntryFlag2ByKey0205a370(struct Container0205a3d0* c, int key) {
    struct Elem0205a370* e = FindEntryByHalfword0205a3d0(c, key);
    if (e == NULL) return;
    if (e->flags15 & 1) {
        e->unk10 = 0;
        e->unk12 = 0;
    }
    e->flags15 &= ~7;
    e->flags15 |= 2;
}
