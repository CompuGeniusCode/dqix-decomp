#include "System/Interrupts.h"
#include <globaldefs.h>

// USA: func_020c6a64
ARM void DMA1InterruptHandler(void) {
    OnDMAOrTimerCompletion(1);
}
