#include <globaldefs.h>

struct TextWindow {
    char unknown0[0xc4];
    unsigned char windowId;
};

struct TextWindowManager {
    char unknown0[0x98];
    int records;
    TextWindow* windows;
    char unknowna0[0x13];
    unsigned char windowCount;
};

extern "C" int IsWindowElementActive(unsigned char* window);
extern "C" void func_0205d904(unsigned char* manager);
extern "C" void func_0204cb20(void* window, int text, int unknownArg4, unsigned char unknownArg5);

// Writes text into the text window with the given id, over the same 0xe0-stride array and +0xc4 id
// byte FindTextWindowById walks, skipping elements IsWindowElementActive rejects; the return is 0
// only when one was found. The scan differs: FindTextWindowById stops at the count in +0xb4, this
// runs the full +0xb3 count, so any window past +0xb4 can be written here yet not be findable.
// Callers pass the buffer they have just formatted; the undecompiled worker at 0x0204cb20 relocates
// to GetMessageWork, FormatMessageText and the markup parser at 0x0204e3e0, and the last two
// arguments reach it untouched - every caller passes 0 or 1 for both and what they select is not
// established. The other guard, +0x98, is the manager's second array, 0x20 bytes an entry with its
// own count at +0xb2, which func_0205d048 resets alongside the windows.
extern "C" ARM int SetTextWindowTextById(struct TextWindowManager* manager, int windowId, int text, int unknownArg4, unsigned char unknownArg5) {
    TextWindow* window;
    unsigned char windowIndex;

    if (text == 0) return 1;
    if (manager->records == 0) return 1;
    if (manager->windows == 0) return 1;

    for (windowIndex = 0; windowIndex < manager->windowCount; windowIndex++) {
        window = (TextWindow*)((char*)manager->windows + windowIndex * 0xe0);
        if (!IsWindowElementActive((unsigned char*)window)) continue;
        if (windowId != window->windowId) continue;
        func_0204cb20(window, text, unknownArg4, unknownArg5);
        func_0205d904((unsigned char*)manager);
        return 0;
    }
    return 1;
}
