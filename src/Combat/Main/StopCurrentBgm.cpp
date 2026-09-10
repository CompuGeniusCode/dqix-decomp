#include <globaldefs.h>

extern "C" void func_0203ac10(void*, void*, int);

struct Actor0209c678 {
    unsigned char pad0[0xb0];
    int state;               // 0xb0
    unsigned char pad1[0x8]; // 0xb4
    void* fieldBC;           // 0xbc
    void* fieldC0;           // 0xc0
    unsigned char pad2[0x4]; // 0xc4
    unsigned char f0 : 1;    // 0xc8 bit0
    unsigned char f1 : 1;    // bit1
    unsigned char f2 : 1;    // bit2
};

// Stops whichever BGM track the player currently has running; the argument is the fade-out
// length, and 0 stops it outright. State 1 means the handle at +0xbc is playing and state 2 the
// one at +0xc0, and func_020bc548 turns a non-zero fade into a volume ramp down to 0 on that
// handle. The object is the BGM player: func_0209c290 opens "data/sound/bgm.sdat" into it and
// SetBgmVolume scales +0xcd against the five-step volume setting at +0xcc. Bit 2 of +0xc8
// suppresses the stop entirely.
extern "C" ARM void StopCurrentBgm(struct Actor0209c678* actor, int arg) {
    if (actor->f2) return;
    if (actor->state == 1) {
        func_0203ac10(actor, &actor->fieldBC, arg);
    } else if (actor->state == 2) {
        func_0203ac10(actor, &actor->fieldC0, arg);
    }
}
