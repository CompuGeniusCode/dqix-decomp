#include <globaldefs.h>
#include "System/Interrupts.h"

int GetData0224e53c_0220d60c(void);

// USA: func_ov031_0220f040
ARM void* GetPtr144If9_0220f040(void) {
    void *result = 0;
    int base = GetData0224e53c_0220d60c();
    int state = DisableIRQInterrupts();
    if (base != 0) {
        if (*(int*)((char*)base + 0x2000 + 0x260) == 9 && *(unsigned char*)((char*)base + 0x2000 + 0x26b) == 0) {
            result = (char*)base + 0x144 + 0x2000;
        }
    }
    SetIRQInterruptState(state);
    return result;
}
