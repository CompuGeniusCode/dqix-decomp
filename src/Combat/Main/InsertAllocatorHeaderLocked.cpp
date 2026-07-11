#include <globaldefs.h>
#include "Memory/SignedAllocator.h"

unsigned int DisableInterrupts(void);
unsigned int RestoreInterrupts(unsigned int mask);

extern SignedAllocatorList data_021103bc;

// USA: func_020bf458
ARM void InsertAllocatorHeaderLocked(SignedAllocatorHeader* header) {
    unsigned int mask = DisableInterrupts();
    data_021103bc.InsertAtEnd(header);
    RestoreInterrupts(mask);
}
