#include "System/Interrupts.h"
#include <globaldefs.h>

// USA: func_020c6a94
ARM void Timer0OverflowInterruptHandler(void) {
    OnDMAOrTimerCompletion(4);
}
