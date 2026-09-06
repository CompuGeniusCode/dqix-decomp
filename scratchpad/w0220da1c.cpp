#include <globaldefs.h>
#include "System/Interrupts.h"
#include "System/Timing.h"

extern int data_ov031_0224e53c;
int RunTwoSteps_0220db28(void);

struct Sub2000_0220da1c { char pad[0x260]; int field260; };

// USA: func_ov031_0220da1c
extern "C" ARM void func_ov031_0220da1c(int value) {
    int state = DisableIRQInterrupts();
    if (*(int*)((char*)data_ov031_0224e53c + 0x2260) == 9) {
        if (value != 9) {
            CancelAlarm((Alarm*)((char*)data_ov031_0224e53c + 0x22cc));
        }
    }
    register Sub2000_0220da1c* sub = (Sub2000_0220da1c*)((char*)data_ov031_0224e53c + 0x2000);
    if (sub->field260 != 0xb) {
        sub->field260 = value;
    }
    if (value == 9) {
        SetTimeout((Alarm*)((char*)data_ov031_0224e53c + 0x22cc), 0x22f5341, (Alarm::PFNCompletion)&RunTwoSteps_0220db28, NULL);
    }
    SetIRQInterruptState(state);
}
