#include <globaldefs.h>
#include "System/Interrupts.h"
#include "System/ProcessorContext.h"

extern "C" void func_ov027_021dd3cc(void *p);
extern "C" void func_ov027_021dd218();

struct RootStruct021dd330 { void *field0; };
extern struct RootStruct021dd330 data_ov027_021e3420;

// USA: func_ov027_021dd330
ARM void InitContextIfFree_021dd330(void *ctxRaw, unsigned int size) {
    int state = DisableIRQInterrupts();
    if (data_ov027_021e3420.field0 == NULL) {
        char *ctx = (char *)ctxRaw;
        data_ov027_021e3420.field0 = ctxRaw;
        func_ov027_021dd3cc(ctx + 0xc4);
        *(unsigned int *)(ctx + 0xc0) = 0;
        unsigned int stackSize = (size - 0xe4) & ~3;
        unsigned int stackBottom = (unsigned int)(ctx + 0xe4) + stackSize;
        PopulateContext((ProcessorContext *)ctxRaw, (unsigned int)func_ov027_021dd218, (unsigned int)ctxRaw, stackBottom, stackSize, 0);
        MarkContextReadyAndSwitch((ProcessorContext *)ctxRaw);
    }
    SetIRQInterruptState(state);
}
