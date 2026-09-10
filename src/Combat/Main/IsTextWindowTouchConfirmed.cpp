#include <globaldefs.h>

struct TouchCursor;
struct TextWindowSet;
struct TextWindow;

extern "C" int func_0205bd20(struct TouchCursor* touchCursor);
extern "C" struct TextWindow* FindTextWindowById(struct TextWindowSet* windowSet, int key);
extern "C" int IsWindowDrawn(unsigned char* window);

struct TextWindowSet {
    char unknown0[0xb0];
    unsigned char activeWindowId;
};

// Answers whether the text window whose id the caller's object holds at +0xb0 has been confirmed
// with the stylus. func_0205bd20 gates on the touch byte at 0x02114ea9 -- the same one
// func_020e1e4c tests before reading stylus coordinates -- and on +0x4c and +0x4e of the touch
// cursor at +0x4, the stylus half EnableTextWindowTouchCursor turns on; FindTextWindowById matches
// that id against the window's own byte at +0xc4, and bit 1 of its byte at +0xc5 is the answer.
// Nothing decompiled ever sets that bit, so "confirmed" rests on the callers, which OR this with "A
// or X newly pressed"; the second argument (always 0x14) is never read.
extern "C" ARM int IsTextWindowTouchConfirmed(struct TextWindowSet* windowSet) {
    unsigned char* window;
    if (func_0205bd20((struct TouchCursor*)((char*)windowSet + 0x4)) == 0) goto ret0;
    window = (unsigned char*)FindTextWindowById((struct TextWindowSet*)windowSet, windowSet->activeWindowId);
    if (window == NULL) goto ret0;
    if (IsWindowDrawn(window) == 0) goto ret0;
    if (window[0xc5] & 2) return 1;
ret0:
    return 0;
}
