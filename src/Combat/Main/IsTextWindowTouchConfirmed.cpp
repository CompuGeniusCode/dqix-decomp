#include <globaldefs.h>

struct Struct_0205bd20;
struct Struct_0205d81c;
struct Elem_0205d81c;

extern "C" int func_0205bd20(struct Struct_0205bd20* s);
extern "C" struct Elem_0205d81c* FindTextWindowById(struct Struct_0205d81c* s, int key);
extern "C" int IsWindowDrawn(unsigned char* obj);

struct Obj_0205da38 {
    char pad0[0xb0];
    unsigned char fb0;
};

// Answers whether the text window whose id the caller's object holds at +0xb0 has been confirmed
// with the stylus. func_0205bd20 gates on the touch byte at 0x02114ea9 -- the same one
// func_020e1e4c tests before reading stylus coordinates -- FindTextWindowById matches that id
// against the window's own byte at +0xc4, and bit 1 of its byte at +0xc5 is the answer. Nothing
// decompiled ever sets that bit, so "confirmed" rests on the callers, which OR this with "A or X
// newly pressed"; the second argument (always 0x14) is never read.
extern "C" ARM int IsTextWindowTouchConfirmed(struct Obj_0205da38* a) {
    unsigned char* e;
    if (func_0205bd20((struct Struct_0205bd20*)((char*)a + 0x4)) == 0) goto ret0;
    e = (unsigned char*)FindTextWindowById((struct Struct_0205d81c*)a, a->fb0);
    if (e == NULL) goto ret0;
    if (IsWindowDrawn(e) == 0) goto ret0;
    if (e[0xc5] & 2) return 1;
ret0:
    return 0;
}
