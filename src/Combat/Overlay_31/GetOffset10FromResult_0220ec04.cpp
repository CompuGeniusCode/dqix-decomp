#include <globaldefs.h>
#include "System/Interrupts.h"

int GetData0224e53c_0220d60c(void);
extern "C" int func_ov031_0220ee50(int);

// USA: func_ov031_0220ec04
ARM int GetOffset10FromResult_0220ec04(int arg) {
    int state = DisableIRQInterrupts();
    int base = GetData0224e53c_0220d60c();
    if (base == 0) {
        SetIRQInterruptState(state);
        return 0;
    }
    int r = func_ov031_0220ee50(arg);
    if (r == 0) {
        SetIRQInterruptState(state);
        return 0;
    }
    SetIRQInterruptState(state);
    return r + 0x10;
}
