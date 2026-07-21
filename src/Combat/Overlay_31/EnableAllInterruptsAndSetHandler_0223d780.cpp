#include <globaldefs.h>
#include "System/Interrupts.h"

void EnableSomeFlag_0223d830(void);

struct S02290d58 { void* handler; unsigned int mask; };
extern S02290d58 data_ov031_02290d58;

// USA: func_ov031_0223d780  (semantic: EnableAllInterruptsAndSetHandler_0223d780)
extern "C" ARM void func_ov031_0223d780(void) {
    volatile unsigned int* reg = (volatile unsigned int*)0x4000210;
    data_ov031_02290d58.mask = *reg;
    SetSpecificInterruptsEnabled(0x40018);
    EnableSpecificInterrupts(1);
    data_ov031_02290d58.handler = (void*)GetInterruptHandler(1);
    SetInterruptHandler(1, (const void*)EnableSomeFlag_0223d830);
    AcknowledgeSpecificInterrupts(1);
    volatile unsigned short* ime = (volatile unsigned short*)0x4000208;
    unsigned short old = *ime;
    (void)old;
    *ime = 1;
    EnableIRQInterrupts();
}
