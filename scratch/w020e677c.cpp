#include <globaldefs.h>
#pragma define_section initcode ".init" RX
#include "Memory/SafeAllocator.h"

ARM SafeAllocator* ResetAndReturnAllocator020dbc48(SafeAllocator* alloc);

extern SafeAllocator data_0214e4c8;

// USA: func_020e677c
extern "C" __declspec(initcode) ARM SafeAllocator* func_020e677c(void) {
    return ResetAndReturnAllocator020dbc48(&data_0214e4c8);
}
