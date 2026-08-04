#include <globaldefs.h>
#include "System/IPC.h"

void InitializeInterProcessorCommunication(void);
bool IsIPCCommandHandlerRegistered(int command, IPCSide side);
void SetArm9IPCCommandHandler(int command, IPCCommandHandler handler);
extern "C" void WaitByLoop(int);
extern "C" void func_020ce308(unsigned int, unsigned int, unsigned int);

struct Ctx021117ec {
    unsigned short flag0;
    short pad2;
    int f4;
    int f8;
    char pad0c[0x1c - 0xc];
    int f1c;
    int f20;
};

extern struct Ctx021117ec data_021117ec;

// USA: func_020ce270  (semantic: InitIPCHandler020ce270)
extern "C" ARM void func_020ce270(void) {
    if (data_021117ec.flag0 != 0) return;
    data_021117ec.flag0 = 1;
    data_021117ec.f1c = 0;
    data_021117ec.f20 = 0;
    InitializeInterProcessorCommunication();
    if (IsIPCCommandHandlerRegistered(8, IPCSide_Arm7) == 0) {
        do {
            WaitByLoop(0x64);
        } while (IsIPCCommandHandlerRegistered(8, IPCSide_Arm7) == 0);
    }
    SetArm9IPCCommandHandler(8, (IPCCommandHandler)func_020ce308);
    int v = *(int*)0x27ffc3c;
    data_021117ec.f8 = v;
    data_021117ec.f4 = v;
}
