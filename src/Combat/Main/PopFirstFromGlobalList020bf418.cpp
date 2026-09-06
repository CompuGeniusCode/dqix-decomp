#include <globaldefs.h>
#include "Memory/SignedAllocator.h"

unsigned int DisableIRQInterrupts(void);
unsigned int SetIRQInterruptState(int mask);

extern SignedAllocatorList data_021103bc;

// USA: func_020bf418
ARM SignedAllocatorHeader* PopFirstFromGlobalList020bf418(void) {
    unsigned int saved = DisableIRQInterrupts();
    SignedAllocatorHeader* e = data_021103bc.ElementAfter(NULL);
    if (e != NULL) {
        data_021103bc.Remove(e);
    }
    SetIRQInterruptState(saved);
    return e;
}
