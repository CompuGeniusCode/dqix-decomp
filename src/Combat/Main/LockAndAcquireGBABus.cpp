#include <globaldefs.h>
#include "System/GamecardBusOwnership.h"
#include "System/Interrupts.h"

extern "C" void WaitByLoop(int);
unsigned short GetLockOwner(GamecardBusLock* lock);

struct Lock020d14e4 {
    int field0;
    unsigned int savedIrq;
};

// USA: func_020d14e4  (semantic: LockAndAcquireGBABus)
extern "C" ARM void func_020d14e4(unsigned short owner, Lock020d14e4* s) {
    for (;;) {
        s->savedIrq = DisableIRQInterrupts();
        int isOwned = GetLockOwner((GamecardBusLock*)0x027fffe8) & 0x40;
        s->field0 = isOwned;
        if (isOwned) return;
        if (!TryAcquireGBABus(owner)) return;
        SetIRQInterruptState(s->savedIrq);
        WaitByLoop(1);
    }
}
