#include <globaldefs.h>

int ReleaseGBABus(unsigned short owner);
typedef int (*ReleaseGBABusRawFn)(int);
unsigned int SetIRQInterruptState(int);

struct Lock020d1540 {
    int field0;
    unsigned int savedIrq;
};

// USA: func_020d1540
ARM unsigned int UnlockAndRestoreInterrupts(int a, struct Lock020d1540* s) {
    if (s->field0 == 0) ((ReleaseGBABusRawFn)&ReleaseGBABus)(a);
    return SetIRQInterruptState(s->savedIrq);
}
