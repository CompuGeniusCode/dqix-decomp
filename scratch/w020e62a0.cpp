#include <globaldefs.h>
#pragma define_section initcode ".init" RX

ARM char* ResetAndReturnSelf0208e870(char* obj);

extern char data_02108fe4;

// USA: func_020e62a0
extern "C" __declspec(initcode) ARM char* func_020e62a0(void) {
    return ResetAndReturnSelf0208e870(&data_02108fe4);
}
