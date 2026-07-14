#include "System/Interrupts.h"
#include <globaldefs.h>

// USA: func_020c6a54
ARM void DMA0InterruptHandler(void) {
    OnDMAOrTimerCompletion(0);
}
