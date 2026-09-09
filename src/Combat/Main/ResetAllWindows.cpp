#include <globaldefs.h>
extern "C" void func_0204c804(void*);

struct Elem0207fe44 { char b[0xe0]; };

struct Cont0207fe44 {
    char pad0[0x30];
    Elem0207fe44* elems;
    char pad34[0x39 - 0x34];
    unsigned char count39;
};

// Resets every element of the window pool at +0x30, count at +0x39, 0xe0 bytes each -- the same
// pool OpenWindowById searches by the id byte at +0xc4 (0xff meaning free), ResetWindowElementById resets a
// single element of, and func_0207fdf0 resets every non-matching element of. The "window" reading
// comes from the sibling parser func_0204cd60 taking FRAME=, TITLE=, CURSOR=, SOLID=, WIRE=, PLTT=
// and SDRC=, from func_0207f914 opening "%s_wnd.bin" into the same struct, and from the element's
// tile-unit rect at +0xa8..+0xae that func_02080d54 scales by 8 to hit-test.
extern "C" ARM void ResetAllWindows(Cont0207fe44* obj) {
    unsigned char count;
    Elem0207fe44* p = obj->elems;
    unsigned char i;
    if (p == NULL) return;
    count = obj->count39;
    for (i = 0; i < count; i++) {
        func_0204c804((void*)(p));
        p++;
    }
}
