#include "System/Interrupts.h"
#include <globaldefs.h>

// USA: func_020c6ac4
ARM void Timer3OverflowInterruptHandler() {
    OnDMAOrTimerCompletion(7);
}
