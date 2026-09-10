#include <globaldefs.h>

struct TextWindow {
    char unknown0[0xc4];
    unsigned char windowId;
    char unknownC5[0xd8 - 0xc5];
    unsigned char fieldD8_bit0 : 1;
    unsigned char fieldD8_rest : 7;
    unsigned char cursorPage;
    unsigned char unknownDA;
    char unknownDB[0xe0 - 0xdb];
};

struct TextWindowSet {
    char unknown0[0x98];
    int bgLayers;
    struct TextWindow* windows;
    char unknownA0[0xb0 - 0xa0];
    unsigned char activeWindowId;
    char unknownB1[0xb3 - 0xb1];
    unsigned char fieldB3;
    char unknownB4[0xb8 - 0xb4];
    unsigned char pendingUploadId;
};

struct TextWindowSet;
extern "C" void* func_0205d888(struct TextWindowSet* p);

extern "C" int func_0205c5b0(void* selfPtr, int cursorInput);
extern "C" unsigned int func_0205c710(unsigned char* windowSet);
extern "C" void func_0205042c(unsigned char* window, unsigned char value);
extern "C" unsigned int func_0205c6e4(unsigned char* windowSet);
extern "C" void func_02050440(unsigned char* window, int value);
extern "C" void func_0204c87c(void* entry, int unused);
extern "C" struct TextWindow* FindTextWindowById(struct TextWindowSet* windowSet, int key);
struct TextWindow;
extern "C" void func_0204ffc0(struct TextWindow* window, int unused);

// One frame of the whole window set. func_0205c5b0 runs the two cursors and returns 0, 1 or 2, and
// when the topmost window (func_0205d888) is the focused one and has its +0xd8 bit set, the active
// cursor has its +0x14 and +0x4 pushed into that window +0xd9 and +0xda -- +0x14 is the page index
// GetGridCursorEntryIndex multiplies by, not the row; the row and column live at +0x18 and +0x1c.
// Every slot below +0xb3 then gets func_0204c87c, and last the id parked at +0xb8 -- 0xff meaning
// none -- is looked up and run through func_0204ffc0, then reset so the re-upload happens once.
// The word at +0x98 the first guard tests is the list of 0x20-byte BG layer descriptors
// ClearBgTilemaps and FlushBgScreenBufferCaches walk, counted at +0xb2, and +0xb3 is the size of
// the window pool SetTextWindowPool hands over, not the number open, which is the separate byte at
// +0xb4. What lives at the cursor +0x4, and so what lands in +0xda, is not established.
extern "C" ARM int UpdateTextWindowSet(void* objPtr, int cursorInput) {
    struct TextWindowSet* windowSet = (struct TextWindowSet*)objPtr;
    int ret;
    struct TextWindow* entry;
    unsigned char window;

    if (windowSet->bgLayers == 0) return 0;
    if (windowSet->windows == 0) return 0;

    ret = 0;
    entry = (struct TextWindow*)func_0205d888((struct TextWindowSet*)objPtr);
    if (entry != 0) {
        ret = func_0205c5b0(objPtr, cursorInput);
        if (windowSet->activeWindowId == entry->windowId) {
            if (entry->fieldD8_bit0) {
                func_0205042c((unsigned char*)entry, func_0205c710((unsigned char*)objPtr));
                func_02050440((unsigned char*)entry, (unsigned char)func_0205c6e4((unsigned char*)objPtr));
            }
        }
    }

    for (window = 0; window < windowSet->fieldB3; window++) {
        func_0204c87c((void*)&windowSet->windows[window], cursorInput);
    }

    if (windowSet->pendingUploadId != 0xff) {
        entry = FindTextWindowById(windowSet, windowSet->pendingUploadId);
        if (entry != 0) {
            func_0204ffc0((struct TextWindow*)entry, -1);
        }
        windowSet->pendingUploadId = 0xff;
    }

    return ret;
}
