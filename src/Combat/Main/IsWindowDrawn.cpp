#include <globaldefs.h>

// Answers whether a window's state word at +0x9c has reached 3, where every path in the per-frame
// update settles: func_0204c87c steps state 1 on and calls func_0204e998, which
// increments again only once (+0xc5 & 1) and the buffer pointer at +0xd4 is non-null, so 1 and 2
// reach 3 only after a buffer is attached; state 4 is forced there and ResetWindowElement leaves
// 0. Callers gate stylus hit-testing and cursor placement on it, so 3 seems to mean the window is
// up and no longer being rebuilt. Nothing decompiled yet writes 1, 2 or 4.
extern "C" ARM int IsWindowDrawn(unsigned char* obj) {
    return *(int*)(obj + 0x9c) == 3;
}
