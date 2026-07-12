#include <globaldefs.h>
void FlagAndRunWithInterruptsDisabled020c7950(struct Obj020c7950*);

extern "C" void func_020c7a90(void*, int);
extern "C" void func_020c7950(void);

extern char data_021118e0;

// USA: func_020cfcbc
ARM asm void InitQueueAndInstallCallback(void* callback) {
    stmdb sp!, {r3, r4, r5, lr}
    ldr r4, =data_021118e0
    mov r5, r0
    ldr r1, [r4, #0x108]
    add r0, r4, #0x44
    bl func_020c7a90
    ldr r1, [r4, #0x114]
    add r0, r4, #0x44
    orr r1, r1, #0x8
    str r0, [r4, #0x104]
    str r5, [r4, #0x40]
    str r1, [r4, #0x114]
    bl func_020c7950
    ldmia sp!, {r3, r4, r5, pc}
}
