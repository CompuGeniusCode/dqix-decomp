#include <globaldefs.h>

unsigned int DisableInterrupts(void);
unsigned int RestoreInterrupts(unsigned int mask);
extern "C" void func_020c7394(void);

// USA: func_020c79a0
ARM void RunWithInterruptsDisabled020c79a0(void) {
    unsigned int mask = DisableInterrupts();
    func_020c7394();
    RestoreInterrupts(mask);
}
