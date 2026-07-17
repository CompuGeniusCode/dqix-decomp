#include <globaldefs.h>
#include "System/Interrupts.h"
#include "System/Memory.h"

struct BufField270_0220eadc {
    void *ptr270;
    int count274;
};

int GetData0224e53c_0220d60c(void);

// USA: func_ov031_0220eadc
ARM void ClearBufIfSet_0220eadc(void) {
    int state = DisableIRQInterrupts();
    int base = GetData0224e53c_0220d60c();
    if (base == 0) {
        SetIRQInterruptState(state);
        return;
    }
    struct BufField270_0220eadc *p = (struct BufField270_0220eadc*)((char*)base + 0x2000);
    if (p->ptr270 != 0 && p->count274 > 0) {
        VectorizedMemset(p->ptr270, 0, p->count274);
    }
    SetIRQInterruptState(state);
}
