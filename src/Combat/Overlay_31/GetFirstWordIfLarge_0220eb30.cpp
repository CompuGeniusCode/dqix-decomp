#include <globaldefs.h>
#include "System/Interrupts.h"

struct BufField270_0220eb30 {
    int *ptr270;
    unsigned int count274;
};

int GetData0224e53c_0220d60c(void);

// USA: func_ov031_0220eb30
ARM int GetFirstWordIfLarge_0220eb30(void) {
    int state = DisableIRQInterrupts();
    int base = GetData0224e53c_0220d60c();
    int result = 0;
    if (base == 0) {
        SetIRQInterruptState(state);
        return result;
    }
    struct BufField270_0220eb30 *p = (struct BufField270_0220eb30*)((char*)base + 0x2000);
    if (p->ptr270 != 0) {
        if (p->count274 > 0xc) {
            result = *p->ptr270;
        }
    }
    SetIRQInterruptState(state);
    return result;
}
