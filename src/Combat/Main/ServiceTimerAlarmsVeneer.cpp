#include <globaldefs.h>

extern "C" void func_020c9198(void);

// USA: func_020c9188
ARM asm int ServiceTimerAlarmsVeneer(int arg) {
    stmdb sp!, {r0, lr}
    bl func_020c9198
    ldmia sp!, {r0, lr}
    bx lr
}
