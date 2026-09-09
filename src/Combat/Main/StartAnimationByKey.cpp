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

extern "C" extern struct Elem0205a370* func_0205a3d0(struct Container0205a3d0*, int);

// Starts the keyed animation playing, rewinding it first if it had already run to its end.
// func_0205a254 is the per-frame tick: it advances an entry only while bit 1 of +0x15 is set, which is
// the state written here, and steps +0x10 as the frame index against the stride-4 duration table at
// +0xc. Word 0 is the loop mode -- a one-shot clamps the index back and calls func_0205a3ac to write
// state 1 at the end, a loop wraps +0x10 to 0 -- so state 1 is finished and state 2 playing, and
// clearing +0x10 and +0x12 here is the rewind of frame and elapsed time.
extern "C" ARM void StartAnimationByKey(struct Container0205a3d0* c, int key) {
    struct Elem0205a370* e = func_0205a3d0(c, key);
    if (e == NULL) return;
    if (e->flags15 & 1) {
        e->unk10 = 0;
        e->unk12 = 0;
    }
    e->flags15 &= ~7;
    e->flags15 |= 2;
}
