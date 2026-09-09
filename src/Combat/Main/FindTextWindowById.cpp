#include <globaldefs.h>

struct Elem_0205d81c {
    char pad0[0xC4];
    unsigned char fieldC4;
    char pad1[0xE0 - 0xC5];
};

struct Struct_0205d81c {
    char pad0[0x98];
    int field98;
    struct Elem_0205d81c* field9C;
    char pad1[0xB3 - 0xA0];
    unsigned char fieldB3;
    unsigned char fieldB4;
};

// Finds the entry carrying the given id in a manager's array; the id is the byte at +0xc4 of each
// 0xe0-byte entry, and the scan stops at whichever of the counts at +0xb3 and +0xb4 comes first.
// The entries are BG text surfaces - +0xa8/+0xaa is their size in tiles, +0xac/+0xae their position
// in tiles, +0xd4 the tilemap buffer - drawn by func_0204cb20 through the markup parser at
// 0x0204e3e0 that reads the bare "SIZE=", "WHITE" and "CURSOR=" tag names in arm9 rodata. Nothing
// in the code calls them windows; the offsets are all that "text window" rests on.
extern "C" ARM struct Elem_0205d81c* FindTextWindowById(struct Struct_0205d81c* s, int key) {
    unsigned char i;
    if (s->field98 == 0) return 0;
    if (s->field9C == 0) return 0;
    for (i = 0; i < s->fieldB3; i++) {
        if (i == s->fieldB4) break;
        if (key == s->field9C[i].fieldC4) return &s->field9C[i];
    }
    return 0;
}
