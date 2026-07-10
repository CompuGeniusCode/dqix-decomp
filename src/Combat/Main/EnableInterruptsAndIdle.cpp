#include <globaldefs.h>

extern unsigned int EnableInterrupts();
extern "C" void func_020c9bf0();

// USA: func_020c7c30
ARM void EnableInterruptsAndIdle() {
    EnableInterrupts();
    for (;;) {
        func_020c9bf0();
    }
}
