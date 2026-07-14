#include <globaldefs.h>

#include "System/IPC.h"

void InitializeInterProcessorCommunication(void);
void SetArm9IPCCommandHandler(int, IPCCommandHandler);
void DispatchType0x11InitOnce(int, int);

struct InitGuard020d1118 { int done; void* callback; };
extern InitGuard020d1118 data_02112140;

// USA: func_020d1118
ARM void RegisterType0x11Handler(void) {
    InitializeInterProcessorCommunication();
    SetArm9IPCCommandHandler(0xe, (IPCCommandHandler)DispatchType0x11InitOnce);
    data_02112140.callback = NULL;
}
