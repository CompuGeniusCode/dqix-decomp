#include <globaldefs.h>

struct Obj2081;

struct Elem2081 {
    char unk[0xc5];
    unsigned char flags;
    char unk2[0x1a];
};

extern "C" struct Elem2081* FindOpenWindowById(struct Obj2081* obj, int key);

// Clears bit 0x20 of the flag byte at +0xc5 of the window with this id, looked up through
// FindOpenWindowById. That bit reads as "hidden": func_0204c8f0 returns before submitting the
// window while it is set, and ov013's func_02186db4 will not place its cursor over one that
// carries it. func_02080c04 is the matching setter and func_02080c3c the query, and ov006's
// func_0215e5f8 flips a group of four windows between set and cleared on one boolean, which is
// what makes "show" rather than something narrower the reading.
extern "C" ARM void ShowWindowById(struct Obj2081* obj, int key) {
    struct Elem2081* elem = FindOpenWindowById(obj, key);
    if (elem != NULL) {
        elem->flags &= ~0x20;
    }
}
