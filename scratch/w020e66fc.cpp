#include <globaldefs.h>
#pragma define_section initcode ".init" RX

struct ResetObj020d7a5c;
ARM struct ResetObj020d7a5c* ResetAndReturnArg020d806c(struct ResetObj020d7a5c* obj);

extern struct ResetObj020d7a5c data_0214e34c;

// USA: func_020e66fc
extern "C" __declspec(initcode) ARM struct ResetObj020d7a5c* func_020e66fc(void) {
    return ResetAndReturnArg020d806c(&data_0214e34c);
}
