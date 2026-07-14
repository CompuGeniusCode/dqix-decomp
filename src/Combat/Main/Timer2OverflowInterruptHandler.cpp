#include "System/Interrupts.h"
#include <globaldefs.h>

// USA: func_020c6ab4
ARM void Timer2OverflowInterruptHandler(void) {
    OnDMAOrTimerCompletion(6);
}
