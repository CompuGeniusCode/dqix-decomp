#include <globaldefs.h>
extern "C" void func_0204c8f0(struct Struct0204c8f0*);

struct Elem0205d228 { char b[0xe0]; };

struct Cont0205d228 {
    char pad0[0x98];
    void* list98;
    Elem0205d228* list9c;
    char padA0[0x13];
    unsigned char countB3;
};

// Runs func_0204c8f0 over every text window -- the array FindTextWindowById searches, 0xe0-byte
// elements at +0x9c, count at +0xb3, keyed by the byte at +0xc4 -- repeating its two null guards on
// +0x98 and +0x9c. func_0204c8f0 skips a window unless it has a target at +0x4, its +0x9c state is
// set, bit 0 of +0xc5 is set and bit 0x20 is clear, then hands +0xac/+0xae, +0xc8, +0xc0 and +0xc2
// to the background-layer path; func_0204b620 is not decompiled, so what that path does with them
// is not established. One of a trio with ClearBgTilemaps and FlushBgScreenBufferCaches over the array at +0x98.
extern "C" ARM void UpdateAllTextWindows(Cont0205d228* obj) {
    unsigned char i;
    if (obj->list98 == NULL || obj->list9c == NULL) return;
    for (i = 0; i < obj->countB3; i++) {
        func_0204c8f0((struct Struct0204c8f0*)(&obj->list9c[i]));
    }
}
