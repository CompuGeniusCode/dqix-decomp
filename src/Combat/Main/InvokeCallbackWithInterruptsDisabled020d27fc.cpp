#include <globaldefs.h>

unsigned int DisableInterrupts();
unsigned int RestoreInterrupts(unsigned int mask);
void InvokeCallbackIfCurrent(int packed);

// USA: func_020d27fc
ARM void InvokeCallbackWithInterruptsDisabled020d27fc(int channel, int packed) {
    unsigned int mask = DisableInterrupts();
    InvokeCallbackIfCurrent(packed);
    RestoreInterrupts(mask);
}
