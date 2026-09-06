#include <globaldefs.h>

unsigned int DisableIRQInterrupts(void);
extern "C" void func_020c9bf0(void);

// USA: func_020c9be0  (semantic: HaltSystem020c9be0)
extern "C" ARM void func_020c9be0(void) {
    for (;;) {
        DisableIRQInterrupts();
        func_020c9bf0();
    }
}
