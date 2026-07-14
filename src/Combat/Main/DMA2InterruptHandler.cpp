#include "System/Interrupts.h"
#include <globaldefs.h>

// USA: func_020c6a74
ARM void DMA2InterruptHandler(void) {
    OnDMAOrTimerCompletion(2);
}
