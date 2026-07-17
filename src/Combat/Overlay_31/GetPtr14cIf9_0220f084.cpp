#include <globaldefs.h>
#include "System/Interrupts.h"

int GetData0224e53c_0220d60c(void);

#pragma optimize_for_size off

// USA: func_ov031_0220f084
ARM void* GetPtr14cIf9_0220f084(unsigned short *out) {
    unsigned short v = 0;
    void *result = 0;
    int base = GetData0224e53c_0220d60c();
    int state = DisableIRQInterrupts();
    if (base != 0) {
        if (*(int*)((char*)base + 0x2000 + 0x260) == 9 && *(unsigned char*)((char*)base + 0x2000 + 0x26b) == 0) {
            v = *(unsigned short*)((char*)base + 0x2100 + 0x4a);
            result = (char*)base + 0x14c + 0x2000;
        }
    }
    SetIRQInterruptState(state);
    if (out != 0) {
        *out = v;
    }
    return result;
}
