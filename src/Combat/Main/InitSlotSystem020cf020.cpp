#include <globaldefs.h>

#include "System/IPC.h"

void InitializeInterProcessorCommunication(void);
bool IsIPCCommandHandlerRegistered(int command, IPCSide side);
void SetArm9IPCCommandHandler(int command, IPCCommandHandler handler);
extern "C" void func_020cf294(void);

extern char data_02111818;

// USA: func_020cf020
ARM void InitSlotSystem020cf020(void) {
    if (*(unsigned short*)(&data_02111818 + 0x0) != 0) return;
    *(unsigned short*)(&data_02111818 + 0x0) = 1;
    *(int*)(&data_02111818 + 0xc) = 0;
    *(int*)(&data_02111818 + 0x10) = 0;
    *(int*)(&data_02111818 + 0x28) = 0;
    *(int*)(&data_02111818 + 0x14) = 0;
    *(int*)(&data_02111818 + 0x18) = 0;
    InitializeInterProcessorCommunication();
    while (IsIPCCommandHandlerRegistered(5, IPCSide_Arm7) == 0) {
    }
    SetArm9IPCCommandHandler(5, (IPCCommandHandler)func_020cf294);
}
