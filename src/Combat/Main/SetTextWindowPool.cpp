#include <globaldefs.h>

struct Elem_0205cf78 {
    struct Elem_0205cf78* prev;
    char pad[0xE0 - 4];
};

struct Struct_0205cf78 {
    char pad0[0x9C];
    struct Elem_0205cf78* field9C;
    char pad1[0xB3 - 0xA0];
    unsigned char fieldB3;
};

// Gives a text window container its storage: the array of 0xe0-byte windows at +0x9c and the count
// at +0xb3, the same pair FindTextWindowById scans by the id byte at +0xc4 and CloseWindows tears
// down from the top. It then points each window's first word at the one before it, which fits the
// container treating them as a stack -- +0xb4 is how many are open. func_0207f7f0 is the identical
// routine for the other window manager, at +0x30 and +0x39.
extern "C" ARM void SetTextWindowPool(struct Struct_0205cf78* s, struct Elem_0205cf78* arr, unsigned char count) {
    unsigned char i;
    s->field9C = arr;
    s->fieldB3 = count;
    if (s->field9C == 0 || s->fieldB3 == 0) return;
    for (i = 1; i < s->fieldB3; i++) {
        s->field9C[i].prev = &s->field9C[i - 1];
    }
}
