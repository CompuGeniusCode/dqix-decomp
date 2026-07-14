#include "System/Interrupts.h"
#include <globaldefs.h>

// USA: func_020c6aa4
ARM void Timer1OverflowInterruptHandler(void) {
    OnDMAOrTimerCompletion(5);
}
