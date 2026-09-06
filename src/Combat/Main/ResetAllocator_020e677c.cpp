#include <globaldefs.h>

#pragma define_section initcode ".init" RX

struct SafeAllocator;
extern "C" void _Z31ResetAndReturnAllocator020dbc48P13SafeAllocator(struct SafeAllocator* obj);

extern struct SafeAllocator data_0214e4c8;

// USA: func_020e677c
extern "C" __declspec(initcode) ARM void __sinit_020e677c(void) {
    _Z31ResetAndReturnAllocator020dbc48P13SafeAllocator(&data_0214e4c8);
}
