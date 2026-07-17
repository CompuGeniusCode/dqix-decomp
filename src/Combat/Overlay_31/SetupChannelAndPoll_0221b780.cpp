#include <globaldefs.h>
#include "System/IPC.h"
#include "System/Cache.h"

extern "C" void WaitByLoop(int);
extern "C" unsigned int SetFieldsA_0221b8b4(int unused, int val, int cond);
extern "C" int func_ov031_0221b284(int a, void* b, unsigned int c, void* d);

// USA: func_ov031_0221b780
ARM void SetupChannelAndPoll_0221b780(void* p0, unsigned int p1, void* p2) {
    while (!IsIPCCommandHandlerRegistered(4, IPCSide_Arm7)) {
    }
    SetArm9IPCCommandHandler(4, (IPCCommandHandler)SetFieldsA_0221b8b4);
    CleanCacheRange(p2, p1);
    do {
        if (func_ov031_0221b284(2, p0, p1, p2) == 1) {
            return;
        }
        WaitByLoop(0x40000);
    } while (1);
}
