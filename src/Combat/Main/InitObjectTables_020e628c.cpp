#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern "C" void _Z24InitObjectTables0208b508Pv(void* obj);

extern char data_02108f0c;

// USA: func_020e628c
extern "C" __declspec(initcode) ARM void __sinit_020e628c(void) {
    _Z24InitObjectTables0208b508Pv(&data_02108f0c);
}
