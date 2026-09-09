#include <globaldefs.h>

// True when a window element is live: it needs both the pointer at +0xd4 and the value at +0x9c.
// The elements are the 0xe0-byte entries of the list at +0x9c, count at +0xb3, and every caller
// uses this to skip the ones not in use. That they are text or message boxes comes from
// func_0204cb20, which func_0205d5d0 runs on the very element this selects and which calls
// GetMessageWork and FormatMessageText.
extern "C" ARM int IsWindowElementActive(unsigned char* obj) {
    if (*(int*)(obj + 0xd4) == 0) return 0;
    return *(int*)(obj + 0x9c) != 0;
}
