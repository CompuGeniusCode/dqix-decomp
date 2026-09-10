#include <globaldefs.h>

struct Elem_0205d81c { char pad0[0xe0]; };

struct Struct_0205d81c {
    char pad0[0x98];
    int field98;                     // 0x98
    struct Elem_0205d81c* field9C;   // 0x9c
    char pad1[0xb0 - 0xa0];
    unsigned char fieldB0;           // 0xb0
    char pad2[0xb4 - 0xb1];
    unsigned char fieldB4;           // 0xb4
};

extern "C" struct Elem_0205d81c* FindTextWindowById(struct Struct_0205d81c*, int);

// Returns the text window whose id the manager holds at +0xb0, or null when none is live.
// FindTextWindowById matches that id against each window's byte at +0xc4, scanning up to +0xb3 and
// breaking at +0xb4; func_0205e00c hands out &field9C[fieldB4] for an absent key, which is
// what makes +0xb4 the live count and +0xb3 the capacity, so the guard added here is just "at least
// one window is live". IsTextWindowTouchConfirmed does the same +0xb0 lookup before testing touch.
extern "C" ARM struct Elem_0205d81c* FindCurrentTextWindow(struct Struct_0205d81c* s) {
    if (s->field98 == 0) return 0;
    if (s->field9C == 0) return 0;
    if (s->fieldB4 == 0) return 0;
    return FindTextWindowById(s, s->fieldB0);
}
