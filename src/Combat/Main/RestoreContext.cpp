#include <globaldefs.h>

struct ProcessorContext;

extern "C" void func_020cd5d4(void);

// USA: func_020c7d80
// Returns from an exception straight into a saved ProcessorContext. func_020cd5d4 restores the
// mathRegisters block at ctx+0x48 first, then the mode is forced to supervisor with IRQ and FIQ
// masked so the banked registers can be written: ctx+0x0 is programStatusRegister and goes back
// into SPSR, ctx+0x4 through ctx+0x3c are userModeRegisters and the ^ on the ldmia makes the last
// two of those the user-mode sp and lr rather than the supervisor pair, ctx+0x40 is resumeAddress
// and ctx+0x44 supervisorStackPointer. The final subs pc, lr, #4 means resumeAddress is stored as
// the interrupted instruction plus 4, the usual exception-return convention. The field names are
// the ones in include/System/ProcessorContext.h.
extern "C" ARM asm void RestoreContext(ProcessorContext* ctx) {
    stmdb sp!, {r0, lr}
    add r0, r0, #0x48
    ldr r1, =func_020cd5d4
    blx r1
    ldmia sp!, {r0, lr}
    mrs r1, cpsr
    bic r1, r1, #0x1f
    orr r1, r1, #0xd3
    msr cpsr_c, r1
    ldr r1, [r0], #0x4
    msr spsr_fsxc, r1
    ldr sp, [r0, #0x40]
    ldr lr, [r0, #0x3c]
    ldmia r0, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, ip, sp, lr}^
    mov r0, r0
    subs pc, lr, #0x4
}
