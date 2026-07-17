#include <globaldefs.h>
#include "System/IPC.h"

extern "C" void WaitByLoop(int);
extern "C" unsigned int SetFieldsA_0221b8b4(int unused, int val, int cond);
extern "C" int func_ov031_0221b284(int a, int b, int c, int d);

// USA: func_ov031_0221b848
ARM int InitAndPollHandler_0221b848(void) {
    while (!IsIPCCommandHandlerRegistered(4, IPCSide_Arm7)) {
    }
    SetArm9IPCCommandHandler(4, (IPCCommandHandler)SetFieldsA_0221b8b4);
    do {
        if (func_ov031_0221b284(7, 0, 0, 0) == 1) {
            break;
        }
        WaitByLoop(0x40000);
    } while (1);
    return 1;
}
