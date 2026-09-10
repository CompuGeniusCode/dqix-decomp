#include <globaldefs.h>

struct TextWindow {
    char unknown0[0xC4];
    unsigned char id;
    char unknownc5[0xE0 - 0xC5];
};

struct TextWindowManager {
    char unknown0[0x98];
    int bgLayers;
    struct TextWindow* windows;
    char unknowna0[0xB3 - 0xA0];
    unsigned char windowCapacity;
    unsigned char openWindowCount;
};

// Finds the entry carrying the given id in a manager's array; the id is the byte at +0xc4 of each
// 0xe0-byte entry, and the scan stops at whichever of the counts at +0xb3 and +0xb4 comes first.
// +0xb3 is the capacity SetTextWindowPool writes when it hands the manager its array, and +0xb4 is
// how many are open, since func_0205e00c hands out &windows[openWindowCount] for an id that is not
// registered yet and CloseWindows counts down from it.
// The entries are BG text surfaces - +0xa8/+0xaa is their size in tiles, +0xac/+0xae their position
// in tiles, +0xd4 the tilemap buffer - drawn by func_0204cb20 through the markup parser at
// 0x0204e3e0 that reads the bare "SIZE=", "WHITE" and "CURSOR=" tag names in arm9 rodata. Nothing
// in the code calls them windows; the offsets are all that "text window" rests on.
// The word at +0x98 is the background-layer array the same manager owns, which
// BindBackgroundLayerToNextWindow walks; here it is only null-checked.
extern "C" ARM struct TextWindow* FindTextWindowById(struct TextWindowManager* manager, int key) {
    unsigned char window;
    if (manager->bgLayers == 0) return 0;
    if (manager->windows == 0) return 0;
    for (window = 0; window < manager->windowCapacity; window++) {
        if (window == manager->openWindowCount) break;
        if (key == manager->windows[window].id) return &manager->windows[window];
    }
    return 0;
}
