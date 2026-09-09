#include "System/Interrupts.h"
#include <globaldefs.h>

extern "C" void WaitByLoop(int);

// Waits out the rest of the frame with WaitForInterrupt(true, 1), mask bit 0 being LCD V-Blank and
// the flag meaning wait for the next one rather than a pending one. That is not the BIOS IntrWait
// at 0x020004ec but the game's own cooperative wait: it clears the pending bit with interrupts off
// and then blocks the current context until the mask fires, yielding to the context scheduler
// instead of halting the CPU. The title, charaview, movieview and charamake loading loops spin on
// this; main() itself calls it once.
extern "C" ARM void WaitForNextVBlank(void) {
    WaitByLoop(1);
    WaitForInterrupt(1, 1);
}
