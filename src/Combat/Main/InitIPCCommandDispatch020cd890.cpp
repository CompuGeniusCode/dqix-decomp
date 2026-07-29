#include <globaldefs.h>
#include "System/IPC.h"

extern "C" void func_020cd610(void);
extern unsigned short data_021117b0;

// USA: func_020cd890  (semantic: InitIPCCommandDispatch020cd890)
extern "C" ARM void func_020cd890(void) {
    if (*(unsigned short*)((char*)&data_021117b0) != 0) return;
    *(unsigned short*)((char*)&data_021117b0) = 1;
    InitializeInterProcessorCommunication();
    *(unsigned short*)((char*)&data_021117b0 + 0x10) = 0;
    *(int*)((char*)&data_021117b0 + 0x4) = 0;
    *(int*)((char*)&data_021117b0 + 0x14) = 0;
    *(unsigned short*)((char*)&data_021117b0 + 0x36) = 0;
    *(unsigned short*)((char*)&data_021117b0 + 0x34) = 0;
    *(unsigned short*)((char*)&data_021117b0 + 0x3a) = 0;
    *(unsigned short*)((char*)&data_021117b0 + 0x38) = 0;
    while (IsIPCCommandHandlerRegistered(6, IPCSide_Arm7) == 0) {
    }
    SetArm9IPCCommandHandler(6, (IPCCommandHandler)func_020cd610);
}
