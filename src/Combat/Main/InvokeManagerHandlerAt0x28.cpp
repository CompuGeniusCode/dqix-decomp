#include <globaldefs.h>
void ScheduleOrInvokeCallback020c76d0(struct Obj020c76d0*, int);

extern unsigned int DisableInterrupts();
extern char data_021112e0;

// USA: func_020c76b0
ARM void InvokeManagerHandlerAt0x28(void) {
    DisableInterrupts();
    ScheduleOrInvokeCallback020c76d0((struct Obj020c76d0*)(*(void**)(&data_021112e0 + 0x28)), (int)(0));
}
