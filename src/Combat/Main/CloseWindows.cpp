#include <globaldefs.h>
extern "C" void func_0205d904(unsigned char*);

struct Struct_0205bf3c;

extern "C" void func_0205d6e4(void* manager, int count);
extern "C" void func_0205bf3c(struct Struct_0205bf3c* s);

struct TextWindowManager {
    char unknown0[0x98];
    int records;
    int windows;
    char unknowna0[0xb3 - 0xa0];
    unsigned char windowCount;
};

// Closes text windows from the top of the manager's array: one, or as many as the array holds
// at +0xb3 when the flag is set -- func_0205d6e4 stops early once the open count at +0xb4 reaches
// zero, so passing the length closes all of them. The entries are the 0xe0-byte windows
// FindTextWindowById searches, and the teardown at func_0204c804 puts each id back to 0xff.
// Afterwards func_0205d904 re-reads whichever window is now on top and recomputes the manager's
// position from its tile coordinates, shifted left three, converting tiles to pixels.
// The other guard, +0x98, is the manager's second array, the 0x20-byte records with their own
// count at +0xb2 that SetTextWindowTextById names. The block at +0x54 that func_0205bf3c zeroes
// sits inside this same manager: UpdateTextWindowSet hands func_0205c5b0 the whole manager, and
// func_0205c5b0 drives +0x4 and +0x54 through two separate sets of helpers, which that function's
// comment reads as the manager's two cursors. What the int, short and three bytes func_0205bf3c
// clears at the block's own +0x30 hold is not established.
extern "C" ARM void CloseWindows(struct TextWindowManager* manager, int closeAll) {
    int count;
    if (manager->records == 0 || manager->windows == 0) return;
    count = 1;
    if (closeAll) count = manager->windowCount;
    func_0205d6e4(manager, count);
    func_0205bf3c((struct Struct_0205bf3c*)((char*)manager + 0x54));
    func_0205d904((unsigned char*)(manager));
}
