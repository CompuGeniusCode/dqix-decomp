#include <globaldefs.h>
#include "System/Interrupts.h"

int SendCommandToArm7(int, int, bool);

struct Ctx021117b0 {
    char pad0[0x4];
    void (*fp4)(int, int, int);
    char pad8[0x38 - 0x8];
    unsigned short half38;
    unsigned short half3a;
};

extern struct Ctx021117b0 data_021117b0;

// USA: func_020cdbe4  (semantic: SendArm7CommandAndUpdateFlags020cdbe4)
extern "C" ARM void func_020cdbe4(void) {
    int state = DisableIRQInterrupts();
    bool ok = SendCommandToArm7(6, 0x3000200, 0) >= 0;
    if (!ok) {
        SetIRQInterruptState(state);
        data_021117b0.half38 |= 0x4;
        if (data_021117b0.fp4 != 0) {
            data_021117b0.fp4(2, 4, 0);
        }
    } else {
        data_021117b0.half3a |= 0x4;
        data_021117b0.half38 &= ~0x4;
        SetIRQInterruptState(state);
    }
}
