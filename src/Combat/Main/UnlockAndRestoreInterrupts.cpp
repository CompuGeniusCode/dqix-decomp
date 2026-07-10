#include <globaldefs.h>

extern "C" void func_020c6fb4(int);
unsigned int RestoreInterrupts(unsigned int);

struct Lock020d1540 {
    int field0;
    unsigned int savedIrq;
};

// USA: func_020d1540
ARM unsigned int UnlockAndRestoreInterrupts(int a, struct Lock020d1540* s) {
    if (s->field0 == 0) func_020c6fb4(a);
    return RestoreInterrupts(s->savedIrq);
}
