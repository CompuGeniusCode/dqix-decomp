#include <globaldefs.h>
extern "C" void func_0204c804(void*);

struct TextWindow { char unknown0[0xe0]; };

struct WindowResource {
    char unknown0[0x30];
    TextWindow* windows;
    char unknown34[0x39 - 0x34];
    unsigned char windowCount;
};

// Resets every element of the window pool at +0x30, count at +0x39, 0xe0 bytes each -- the same
// pool OpenWindowById searches by the id byte at +0xc4 (0xff meaning free), ResetWindowElementById resets a
// single element of, and func_0207fdf0 resets every non-matching element of. The "window" reading
// comes from the sibling parser func_0204cd60 taking FRAME=, TITLE=, CURSOR=, SOLID=, WIRE=, PLTT=
// and SDRC=, from QueueTextAndWindowFiles opening "%s_wnd.bin" into the same struct, and from the
// element's tile-unit rect at +0xa8..+0xae that func_02080d54 scales by 8 to hit-test. The elements
// are the same 0xe0-byte struct the text-window container holds at +0x9c -- same id byte, same
// func_0204c804 teardown -- so they carry the same tag here, while the container is the other of
// the two, the resource QueueTextAndWindowFiles loads the three layout files into.
extern "C" ARM void ResetAllWindows(WindowResource* resource) {
    unsigned char count;
    TextWindow* window = resource->windows;
    unsigned char windowIndex;
    if (window == NULL) return;
    count = resource->windowCount;
    for (windowIndex = 0; windowIndex < count; windowIndex++) {
        func_0204c804((void*)(window));
        window++;
    }
}
