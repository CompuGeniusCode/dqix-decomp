#include <globaldefs.h>
#pragma define_section initcode ".init" RX

ARM void* InitObjectTables0208b508(void* obj);

extern int data_02108f0c;

// USA: func_020e628c
extern "C" __declspec(initcode) ARM void* func_020e628c(void) {
    return InitObjectTables0208b508(&data_02108f0c);
}
