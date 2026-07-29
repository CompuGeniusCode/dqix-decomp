#include <globaldefs.h>
#pragma define_section initcode ".init" RX
#include "Memory/SafeAllocator.h"

ARM SafeAllocator* ResetAndReturnAllocator(SafeAllocator* alloc);

extern SafeAllocator data_0210783c;

// USA: func_020e5d84
extern "C" __declspec(initcode) ARM SafeAllocator* func_020e5d84(void) {
    return ResetAndReturnAllocator(&data_0210783c);
}
