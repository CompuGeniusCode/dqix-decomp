#include <globaldefs.h>
#include "System/IPC.h"
#include "System/Cache.h"

unsigned int SetFieldsA_0221b8b4(int, int, int);
extern "C" int func_ov031_0221b284(int, int, int, int);
extern "C" void WaitByLoop(int);

// USA: func_ov031_0221b6f0
extern "C" ARM int func_ov031_0221b6f0(int a0, int a1, int a2) {
    InvalidateDataCacheRange((const void*)a2, a1);
    while (IsIPCCommandHandlerRegistered(4, IPCSide_Arm7) == 0) {
    }
    SetArm9IPCCommandHandler(4, (IPCCommandHandler)SetFieldsA_0221b8b4);
    for (;;) {
        if (func_ov031_0221b284(1, a0, (unsigned short)a1, a2) == 1) {
            break;
        }
        WaitByLoop(0x40000);
    }
    InvalidateDataCacheRange((const void*)a2, a1);
    return 1;
}
