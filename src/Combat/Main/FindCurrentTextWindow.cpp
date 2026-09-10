#include <globaldefs.h>

struct TextWindow { char unknown0[0xe0]; };

struct TextWindowManager {
    char unknown0[0x98];
    int bgLayers;                     // 0x98
    struct TextWindow* windows;   // 0x9c
    char unknowna0[0xb0 - 0xa0];
    unsigned char activeWindowId;           // 0xb0
    char unknownb1[0xb4 - 0xb1];
    unsigned char openCount;           // 0xb4
};

extern "C" struct TextWindow* FindTextWindowById(struct TextWindowManager*, int);

// Returns the text window whose id the manager holds at +0xb0, or null when none is live.
// FindTextWindowById matches that id against each window's byte at +0xc4, scanning up to +0xb3 and
// breaking at +0xb4; func_0205e00c hands out &windows[openCount] for an absent key, which is
// what makes +0xb4 the live count and +0xb3 the capacity, so the guard added here is just "at least
// one window is live". IsTextWindowTouchConfirmed does the same +0xb0 lookup before testing touch.
// The first guard, +0x98, is the manager's other array -- 0x20 bytes an entry, counted at +0xb2 --
// that UpdateTextWindowSet reads as the BG layer descriptors ClearBgTilemaps walks; the capacity
// byte at +0xb3 is left inside the filler here because this function never reads it.
extern "C" ARM struct TextWindow* FindCurrentTextWindow(struct TextWindowManager* manager) {
    if (manager->bgLayers == 0) return 0;
    if (manager->windows == 0) return 0;
    if (manager->openCount == 0) return 0;
    return FindTextWindowById(manager, manager->activeWindowId);
}
