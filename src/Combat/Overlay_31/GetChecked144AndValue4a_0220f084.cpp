#include <globaldefs.h>
#include "System/Interrupts.h"

int GetData0224e53c_0220d60c(void);

// USA: func_ov031_0220f084  (semantic: GetChecked144AndValue4a_0220f084)
#pragma optimize_for_size off
extern "C" ARM void* func_ov031_0220f084(unsigned short* out) {
    void* result = NULL;
    unsigned short val = 0;
    int base = GetData0224e53c_0220d60c();
    unsigned int state = DisableIRQInterrupts();
    if (base != 0) {
        if (*(int*)((char*)base + 0x2260) == 9 && *(unsigned char*)((char*)base + 0x226b) == 0) {
            val = *(unsigned short*)((char*)base + 0x214a);
            result = (char*)base + 0x214c;
        }
    }
    SetIRQInterruptState(state);
    if (out != NULL) {
        *out = val;
    }
    return result;
}
