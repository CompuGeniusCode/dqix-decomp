#include <globaldefs.h>

unsigned int DisableIRQInterrupts(void);
extern "C" void func_020c9bf0(void);

// Never returns: disables IRQs and parks the CPU on the CP15 wait-for-interrupt, forever. It seems
// to be the assertion-failure path -- there is no assert string in it, but all 108 call sites are
// checks that cannot be recovered from, such as an allocator returning null or a chunk missing from
// an archive. func_020ce7a4 is the longer shutdown that drains pending work before doing the same.
extern "C" ARM void FatalHalt(void) {
    for (;;) {
        DisableIRQInterrupts();
        func_020c9bf0();
    }
}
