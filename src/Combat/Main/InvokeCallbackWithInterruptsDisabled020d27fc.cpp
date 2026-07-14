#include <globaldefs.h>

unsigned int DisableIRQInterrupts();
unsigned int SetIRQInterruptState(int mask);
void InvokeCallbackIfCurrent(int packed);

// USA: func_020d27fc
ARM void InvokeCallbackWithInterruptsDisabled020d27fc(int channel, int packed) {
    unsigned int mask = DisableIRQInterrupts();
    InvokeCallbackIfCurrent(packed);
    SetIRQInterruptState(mask);
}
