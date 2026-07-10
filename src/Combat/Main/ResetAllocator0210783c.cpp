#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

ARM SafeAllocator* ResetAndReturnAllocator(SafeAllocator* alloc);

extern int data_0210783c;

// USA: func_020e5d84
ARM SafeAllocator* ResetAllocator0210783c(void) {
    return ResetAndReturnAllocator((SafeAllocator*)&data_0210783c);
}
