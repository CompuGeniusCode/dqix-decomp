#include <globaldefs.h>
#include "System/Interrupts.h"

int GetData0224e53c_0220d60c(void);

// USA: func_ov031_0220eb88
ARM int GetFlagAndSetFlag_0220eb88(int arg) {
    int state = DisableIRQInterrupts();
    int base = GetData0224e53c_0220d60c();
    if (base == 0) {
        SetIRQInterruptState(state);
        return 0;
    }
    unsigned char flag = *((unsigned char*)base + 0x2000 + 0x26a);
    int result;
    int newVal;
    if (arg != 0) {
        result = (flag != 0) ? 1 : 0;
        base = base + 0x2000;
        newVal = 1;
    } else {
        result = (flag != 0) ? 1 : 0;
        base = base + 0x2000;
        newVal = 0;
    }
    *((unsigned char*)base + 0x26a) = newVal;
    SetIRQInterruptState(state);
    return result;
}
