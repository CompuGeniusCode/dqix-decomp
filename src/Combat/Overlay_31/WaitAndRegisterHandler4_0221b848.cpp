#include <globaldefs.h>
#include "System/IPC.h"

unsigned int SetFieldsA_0221b8b4(int, int, int);
extern "C" int func_ov031_0221b284(int, int, int, int);
extern "C" void WaitByLoop(int);

// USA: func_ov031_0221b848  (semantic: WaitAndRegisterHandler4_0221b848)
extern "C" ARM int func_ov031_0221b848(void) {
    while (IsIPCCommandHandlerRegistered(4, IPCSide_Arm7) == 0) {
    }
    SetArm9IPCCommandHandler(4, (IPCCommandHandler)SetFieldsA_0221b8b4);
    for (;;) {
        if (func_ov031_0221b284(7, 0, 0, 0) == 1) {
            break;
        }
        WaitByLoop(0x40000);
    }
    return 1;
}
