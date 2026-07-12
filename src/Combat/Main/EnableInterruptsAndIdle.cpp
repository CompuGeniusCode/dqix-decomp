#include <globaldefs.h>
extern "C" void func_020c9bf0(void);

extern unsigned int EnableInterrupts();

// USA: func_020c7c30
ARM void EnableInterruptsAndIdle() {
    EnableInterrupts();
    for (;;) {
        func_020c9bf0();
    }
}
