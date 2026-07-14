#include "System/Interrupts.h"
#include <globaldefs.h>

// USA: func_020c6a84
ARM void DMA3InterruptHandler(void) {
    OnDMAOrTimerCompletion(3);
}
