#include <globaldefs.h>

// True while a sub screen brightness fade is still running. Fields 0x1c and 0x20 hold the sub
// screen's target value and its remaining time, which SetSubScreenBrightness writes; 0x10 and 0x14
// are the main engine's pair, tested by the twin at 0x0203b398. IsScreenFadeActive is just the OR of
// the two. The remaining time is in milliseconds, converted from a frame count at roughly 16.667 ms
// per frame.
extern "C" ARM int IsSubScreenFadeActive(int* obj) {
    return obj[8] > 0;
}
