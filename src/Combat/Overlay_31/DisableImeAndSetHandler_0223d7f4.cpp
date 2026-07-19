#include <globaldefs.h>
#include "System/Interrupts.h"

unsigned int SetSpecificInterruptsEnabled(unsigned int which);

struct S02290d58 { void* handler; unsigned int mask; };
extern S02290d58 data_ov031_02290d58;

// USA: func_ov031_0223d7f4
ARM void DisableImeAndSetHandler_0223d7f4(void) {
    volatile unsigned short* ime = (volatile unsigned short*)0x4000208;
    unsigned short old = *ime;
    (void)old;
    *ime = 0;
    SetSpecificInterruptsEnabled(data_ov031_02290d58.mask);
    SetInterruptHandler(1, data_ov031_02290d58.handler);
}
