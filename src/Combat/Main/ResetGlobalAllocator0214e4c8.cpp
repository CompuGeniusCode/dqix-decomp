#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

SafeAllocator* ResetAndReturnAllocator020dbc48(SafeAllocator* alloc);
extern char data_0214e4c8;

// USA: func_020e677c
ARM SafeAllocator* ResetGlobalAllocator0214e4c8(void) {
    return ResetAndReturnAllocator020dbc48((SafeAllocator*)&data_0214e4c8);
}
