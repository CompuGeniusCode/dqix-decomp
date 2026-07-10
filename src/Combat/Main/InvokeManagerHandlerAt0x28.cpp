#include <globaldefs.h>

extern unsigned int DisableInterrupts();
extern char data_021112e0;
extern "C" void func_020c76d0(void*, int);

// USA: func_020c76b0
ARM void InvokeManagerHandlerAt0x28(void) {
    DisableInterrupts();
    func_020c76d0(*(void**)(&data_021112e0 + 0x28), 0);
}
