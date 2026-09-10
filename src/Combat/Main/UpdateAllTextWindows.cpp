#include <globaldefs.h>
extern "C" void func_0204c8f0(struct TextWindowEntry*);

struct TextWindow { char unknown0[0xe0]; };

struct TextWindowSet {
    char unknown0[0x98];
    void* bgLayers;
    TextWindow* windows;
    char unknowna0[0x13];
    unsigned char windowPoolSize;
};

// Runs func_0204c8f0 over every text window -- the array FindTextWindowById searches, 0xe0-byte
// elements at +0x9c, count at +0xb3, keyed by the byte at +0xc4 -- repeating its two null guards on
// +0x98 and +0x9c. func_0204c8f0 skips a window unless it has a target at +0x4, its +0x9c state is
// set, bit 0 of +0xc5 is set and bit 0x20 is clear, then hands +0xac/+0xae, +0xc8, +0xc0 and +0xc2
// to the background-layer path; func_0204b620 is not decompiled, so what that path does with them
// is not established. One of a trio with ClearBgTilemaps and FlushBgScreenBufferCaches over the array at +0x98.
// The count it runs to is the size of the pool SetTextWindowPool handed over rather than the number
// of windows open, which is the separate byte at +0xb4, so unused slots are visited too.
extern "C" ARM void UpdateAllTextWindows(TextWindowSet* windowSet) {
    unsigned char window;
    if (windowSet->bgLayers == NULL || windowSet->windows == NULL) return;
    for (window = 0; window < windowSet->windowPoolSize; window++) {
        func_0204c8f0((struct TextWindowEntry*)(&windowSet->windows[window]));
    }
}
