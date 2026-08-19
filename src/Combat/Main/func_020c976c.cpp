#include <globaldefs.h>

// USA: func_020c976c
// PROVENANCE: SonicRushAdventure-Decomp/lib/NitroSDK/src/os/os_system.c — OS_SpinWait. Busy-loop
// delay: burns `cycles` at 4 per iteration.
extern "C" ARM asm void func_020c976c(unsigned int cycles) {
loop:
    subs r0, r0, #4
    bhs loop
    bx lr
}
