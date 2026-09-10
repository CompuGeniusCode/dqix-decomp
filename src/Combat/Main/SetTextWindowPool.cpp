#include <globaldefs.h>

struct TextWindow {
    struct TextWindow* prev;
    char unknown4[0xE0 - 4];
};

struct TextWindowManager {
    char unknown0[0x9C];
    struct TextWindow* windows;
    char unknowna0[0xB3 - 0xA0];
    unsigned char windowCount;
};

// Gives a text window manager its storage: the array of 0xe0-byte windows at +0x9c and the count
// at +0xb3, the same pair FindTextWindowById scans by the id byte at +0xc4 and CloseWindows tears
// down from the top. It then points each window's first word at the one before it, which fits the
// manager treating them as a stack -- +0xb4 is how many are open. func_0207f7f0 is the identical
// routine for the other window manager, at +0x30 and +0x39.
extern "C" ARM void SetTextWindowPool(struct TextWindowManager* manager, struct TextWindow* arr, unsigned char count) {
    unsigned char windowIndex;
    manager->windows = arr;
    manager->windowCount = count;
    if (manager->windows == 0 || manager->windowCount == 0) return;
    for (windowIndex = 1; windowIndex < manager->windowCount; windowIndex++) {
        manager->windows[windowIndex].prev = &manager->windows[windowIndex - 1];
    }
}
