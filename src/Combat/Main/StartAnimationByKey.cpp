#include <globaldefs.h>

struct AnimationEntry {
    char unknown0[0x10];
    unsigned short frameIndex;
    unsigned short elapsedTime;
    unsigned char unknown14;
    unsigned char flags15;
    char unknown16[2];
};

struct AnimationEntryList;

extern "C" extern struct AnimationEntry* FindAnimationByKey(struct AnimationEntryList*, int);

// Starts the keyed animation playing, rewinding it first if it had already run to its end.
// func_0205a254 is the per-frame tick: it advances an entry only while bit 1 of +0x15 is set, which is
// the state written here, and steps +0x10 as the frame index against the stride-4 duration table at
// +0xc. Word 0 is the loop mode -- a one-shot clamps the index back and calls func_0205a3ac to write
// state 1 at the end, a loop wraps +0x10 to 0 -- so state 1 is finished and state 2 playing, and
// clearing +0x10 and +0x12 here is the rewind of frame and elapsed time.
// The entries are the 0x18-byte cell-animation records FindAnimationByKey keys by the halfword at
// +8; the unnamed head covers the loop mode at 0, the screen position at +4/+6 and the duration
// table pointer at +0xc, none of which this function touches.
extern "C" ARM void StartAnimationByKey(struct AnimationEntryList* animations, int key) {
    struct AnimationEntry* entry = FindAnimationByKey(animations, key);
    if (entry == NULL) return;
    if (entry->flags15 & 1) {
        entry->frameIndex = 0;
        entry->elapsedTime = 0;
    }
    entry->flags15 &= ~7;
    entry->flags15 |= 2;
}
