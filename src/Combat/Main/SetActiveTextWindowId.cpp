#include <globaldefs.h>
extern "C" void func_0205d904(unsigned char*);

struct TextWindowManager {
    char unknown0[0xb0];
    unsigned char activeWindowId;           // 0xb0
};

// Stores the id of the window the text-window manager should treat as current, then calls
// func_0205d904 so the manager re-reads it: that refreshes the four cached substruct
// pointers and copies the window's tile position from +0xac/+0xae into +0x3c/+0x3e shifted left by
// 3, i.e. converted to pixels. FindCurrentTextWindow and IsTextWindowTouchConfirmed key their
// lookups off the same +0xb0 byte, which is what makes it the selection. "Text window" is this
// pass's own vocabulary for these objects, not an upstream name, and is not independently anchored.
extern "C" ARM void SetActiveTextWindowId(struct TextWindowManager* manager, int windowId) {
    manager->activeWindowId = windowId;
    func_0205d904((unsigned char*)(manager));
}
