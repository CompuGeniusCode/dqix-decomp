#include <globaldefs.h>

unsigned int DisableIRQInterrupts(void);
unsigned int SetIRQInterruptState(int mask);

struct Global021117b0 { int f0; int f4; };
extern Global021117b0 data_021117b0;

// USA: func_020cdac4
ARM void StoreValueWithInterruptsDisabled020cdac4(int value) {
    unsigned int mask;
    mask = DisableIRQInterrupts();
    data_021117b0.f4 = value;
    SetIRQInterruptState(mask);
}
