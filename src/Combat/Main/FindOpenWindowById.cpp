#include <globaldefs.h>

struct Elem2081 {
    char unk[0xc4];
    unsigned char key;
    char unk2[0x1b];
};

struct Obj2081 {
    char unk[0x30];
    struct Elem2081* elems;
    char unk2[5];
    unsigned char count;
};

// Scans the window array at +0x30 - 0xe0 bytes per window, count at +0x39 - for the one whose id
// byte at +0xc4 matches, returning null when none does. OpenWindowById calls this first and only
// when it comes back null falls through to func_02081de0, which is the same scan looking for id
// 0xff, so 0xff marks an unused window slot.
extern "C" ARM struct Elem2081* FindOpenWindowById(struct Obj2081* obj, int key) {
    unsigned char count = obj->count;
    struct Elem2081* p = obj->elems;
    unsigned char i;
    for (i = 0; i < count; i++) {
        if (key == p->key) {
            return p;
        }
        p++;
    }
    return NULL;
}
