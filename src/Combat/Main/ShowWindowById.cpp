#include <globaldefs.h>

struct WindowResource;

struct WindowElement {
    char unknown0[0xc5];
    unsigned char flags;
    char unknownc6[0x1a];
};

extern "C" struct WindowElement* FindOpenWindowById(struct WindowResource* obj, int key);

// Clears bit 0x20 of the flag byte at +0xc5 of the window with this id, looked up through
// FindOpenWindowById. That bit reads as "hidden": func_0204c8f0 returns before submitting the
// window while it is set, and ov013's func_02186db4 will not place its cursor over one that
// carries it. func_02080c04 is the matching setter and func_02080c3c the query, and ov006's
// func_0215e5f8 flips a group of four windows between set and cleared on one boolean, which is
// what makes "show" rather than something narrower the reading. A window is 0xe0 bytes in the
// array the resource keeps at +0x30, with the id byte FindOpenWindowById matches at +0xc4, so
// this flag byte is the one immediately after that id.
extern "C" ARM void ShowWindowById(struct WindowResource* obj, int key) {
    struct WindowElement* window = FindOpenWindowById(obj, key);
    if (window != NULL) {
        window->flags &= ~0x20;
    }
}
