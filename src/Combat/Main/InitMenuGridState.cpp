#include <globaldefs.h>

struct Struct_0205c53c;
extern "C" extern void func_0205c53c(struct Struct_0205c53c* s);

struct InitTarget0205cfd4 {
    char pad0[0x98];
    int f98;
    int f9c;
    unsigned short fa0;
    unsigned short fa2;
    unsigned short fa4;
    unsigned short fa6;
    unsigned short fa8;
    unsigned short faa;
    unsigned short fac;
    unsigned short fae;
    unsigned char fb0;
    unsigned char fb1;
    unsigned char fb2;
    unsigned char fb3;
    unsigned char fb4;
    unsigned char fb5;
    unsigned char fb6;
    unsigned char fb7;
    unsigned char fb8;
};

// Initialises a menu object that owns two grid cursors: func_0205c53c sets up the
// sub-objects at +4 and +0x54, and the sibling 0x0205cf28 drives both through the curated
// SetGridCursorLayout and SetGridItemCountAndClampCursor. The rest is the element array at +0x9c,
// 0xe0 bytes per entry, and the record array at +0x98, 0x20 bytes per entry, that 0x0205d048 tears
// back down. The defaults written here come in per-screen pairs -- 1/1, 0/0, 4/4, 0xa/0xb -- but
// what they configure, and what the 0xa and 0xff at +0xb7 and +0xb8 mean, is not established.
extern "C" ARM void InitMenuGridState(struct InitTarget0205cfd4* s) {
    func_0205c53c((struct Struct_0205c53c*)s);
    s->f98 = 0;
    s->f9c = 0;
    s->fa0 = 1;
    s->fa2 = 1;
    s->fa4 = 0;
    s->fa6 = 0;
    s->fa8 = 4;
    s->faa = 4;
    s->fac = 0xa;
    s->fae = 0xb;
    s->fb0 = 0;
    s->fb1 = 0;
    s->fb2 = 0;
    s->fb3 = 0;
    s->fb4 = 0;
    s->fb5 = 0;
    s->fb6 = 0;
    s->fb7 = 0xa;
    s->fb8 = 0xff;
}
