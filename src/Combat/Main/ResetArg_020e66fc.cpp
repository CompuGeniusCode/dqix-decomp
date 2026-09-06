#include <globaldefs.h>

#pragma define_section initcode ".init" RX

struct ResetObj020d7a5c;
extern "C" void _Z25ResetAndReturnArg020d806cP16ResetObj020d7a5c(struct ResetObj020d7a5c* obj);

extern struct ResetObj020d7a5c data_0214e34c;

// USA: func_020e66fc
extern "C" __declspec(initcode) ARM void __sinit_020e66fc(void) {
    _Z25ResetAndReturnArg020d806cP16ResetObj020d7a5c(&data_0214e34c);
}
