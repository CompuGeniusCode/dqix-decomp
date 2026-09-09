#include <globaldefs.h>

// True when any key in the mask is down this frame and was not down last frame. The pointer is the
// pad state at data_02114e30: func_0201229c copies the previous reading into the second halfword
// and refills the first from func_02012354 (REG_KEYINPUT or'd with the ARM7 key extension at
// 0x27fffa8), and zeroes both while the lid is shut or a master-brightness fade is running.
// Call-site masks are ordinary DS keypad bits, so 0x802 is Y|B. func_02012468 is the mirror image
// (released this frame) and func_0201248c layers key repeat on this with an eight-tick delay.
extern "C" ARM int IsKeyTriggered(unsigned short* obj, int mask) {
    if ((obj[0] & mask) != 0 && (obj[1] & mask) == 0) {
        return 1;
    }
    return 0;
}
