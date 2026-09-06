#include <globaldefs.h>

unsigned int DisableIRQInterrupts(void);
void ResetAllDMAChannels(void);

extern "C" int func_020ce758(void);
extern "C" void func_020c976c(unsigned int id);
extern "C" void func_020c9bf0(void);

// USA: func_020ce7a4
// Fatal-shutdown sequence: drain pending work via func_020ce758/func_020c976c,
// then disable interrupts, reset DMA, and halt forever.
ARM void TerminateSystem020ce7a4(void) {
    if (func_020ce758()) {
        do {
            func_020c976c(0xa3a47);
        } while (func_020ce758());
    }
    DisableIRQInterrupts();
    ResetAllDMAChannels();
    for (;;) {
        func_020c9bf0();
    }
}
