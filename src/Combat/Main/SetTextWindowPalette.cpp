#include <globaldefs.h>

struct TextWindow {
    char pad0[0xc2];
    unsigned short fieldC2;          // 0xc2
    char pad1[0xe0 - 0xc4];
};

struct TextWindowSet {
    char pad0[0x98];
    int field98;                     // 0x98
    struct TextWindow* field9C;   // 0x9c
    char pad1[0xe0 - 0xa0];
};

extern "C" struct TextWindow* FindTextWindowById(struct TextWindowSet*, int);

// Sets one text window's BG palette. The key is the window id at +0xc4 that FindTextWindowById
// looks up - ResetWindowElement (0x0204c684) parks that byte at 0xff on a free slot - and the
// value is masked to four bits and stored as the halfword at +0xc2.
// That halfword is the palette number the window's tile copy stamps into the BG screen:
// func_0204c8f0 passes it to func_0204b878 and on to 0x0204b620, which clears bits 12-15 of every
// entry it writes and ORs this value in, unless the halfword reads 0xffff, which means keep the
// source palette. Since this masks to 0xf it can never write that sentinel.
// Nothing happens if the set has no BG layer table (+0x98) or no window array (+0x9c).
extern "C" ARM void SetTextWindowPalette(struct TextWindowSet* windowSet, int windowId, int palette) {
    struct TextWindow* window;
    if (windowSet->field98 == 0 || windowSet->field9C == 0) return;
    window = FindTextWindowById(windowSet, windowId);
    if (window != 0) {
        unsigned short maskedPalette = palette & 0xf;
        window->fieldC2 = maskedPalette & 0xf;
    }
}
