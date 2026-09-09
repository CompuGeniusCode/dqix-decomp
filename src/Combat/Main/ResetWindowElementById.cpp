#include <globaldefs.h>
extern "C" void func_0204c804(void*);

struct Elem2081;

struct Obj2081 {
    char pad0[0x30];
    struct Elem2081* elems;
};

extern "C" extern struct Elem2081* FindOpenWindowById(struct Obj2081* obj, int key);

// Resets the one element of a loaded window layout whose id byte at 0xc4 matches. The owning object
// is the window resource itself: QueueTextAndWindowFiles puts its three BackgroundLoader handles for
// "%s_<LG>.bin", "%s_txt.bin" and "%s_wnd.bin" at 0x20, 0x24 and 0x28, and the element array and
// count sit at 0x30 and 0x39. func_0204c804 zeroes the element's position and size shorts, puts 4
// back at 0xb0 and 0xb2 and 0xff back in the id byte -- the free marker OpenWindowById and
// FindTextWindowById also test, on the same 0xE0 stride. Menu code calls this when a panel closes.
extern "C" ARM void ResetWindowElementById(struct Obj2081* obj, int key) {
    struct Elem2081* e;
    if (obj->elems == NULL) return;
    e = FindOpenWindowById(obj, key);
    if (e == NULL) return;
    func_0204c804((void*)(e));
}
