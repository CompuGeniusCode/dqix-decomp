#include <globaldefs.h>

extern "C" unsigned int DisableInterrupts(void);
extern "C" void func_020c9bf0(void);

// USA: func_020c9be0
ARM void HaltSystem(void) {
    for (;;) {
        DisableInterrupts();
        func_020c9bf0();
    }
}
