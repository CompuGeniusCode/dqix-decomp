#include <globaldefs.h>

struct Elem0205a42c {
    char unk0[0x14];
    unsigned char unk14;
    char unk15[3];
};

struct Container0205a3d0;

extern struct Elem0205a42c* FindEntryByHalfword0205a3d0(struct Container0205a3d0*, int);

// USA: func_0205a42c
ARM void SetEntryByte14ByKey0205a42c(struct Container0205a3d0* c, int key, int val) {
    struct Elem0205a42c* e = FindEntryByHalfword0205a3d0(c, key);
    if (e != NULL) {
        e->unk14 = val;
    }
}
