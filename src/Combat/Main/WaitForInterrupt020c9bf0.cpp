#include <globaldefs.h>

// USA: func_020c9bf0  (semantic: WaitForInterrupt020c9bf0)
extern "C" ARM void func_020c9bf0(void) {
    asm {
        mov r0, 0
        mcr p15, 0, r0, c7, c0, 4
    }
}
