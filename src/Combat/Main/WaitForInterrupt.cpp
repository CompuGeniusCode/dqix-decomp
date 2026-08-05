#include <globaldefs.h>
#include "System/Interrupts.h"

extern "C" void func_020c9bf0(void);
extern char data_027e0000;

#define INTERRUPT_MASTER_ENABLE (*(volatile unsigned short*)0x04000208)

// USA: func_020c9778  (semantic: WaitForInterrupt)
extern "C" ARM void func_020c9778(bool onlySubsequent, unsigned int mask) {
    int oldState = DisableIRQInterrupts();
    unsigned short oldIME = INTERRUPT_MASTER_ENABLE;
    INTERRUPT_MASTER_ENABLE = 1;

    if (onlySubsequent) {
        *(unsigned int*)((char*)&data_027e0000 + 0x3ff8) &= ~mask;
    }

    unsigned int* flags = (unsigned int*)((char*)&data_027e0000 + 0x3ff8);
    if ((mask & *(unsigned int*)((char*)&data_027e0000 + 0x3ff8)) == 0) {
        do {
            func_020c9bf0();
            EnableIRQInterrupts();
            DisableIRQInterrupts();
        } while ((mask & *flags) == 0);
    }
    *flags &= ~mask;

    (void)INTERRUPT_MASTER_ENABLE;
    INTERRUPT_MASTER_ENABLE = oldIME;

    SetIRQInterruptState(oldState);
}
