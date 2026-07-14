#include <globaldefs.h>
#include "std_library_functions.h"
int GetGlobalField0x1c020421a0(void);
extern "C" void func_02046608(void);
// USA: func_02098f70
ARM asm void AppendFormattedData02098f70(int* cursor, void* data, int size, int advance) {
    stmdb sp!, {r3, r4, r5, r6, r7, r8, lr}
    sub sp, sp, #0xc
    mov r4, r0
    mov r8, r1
    mov r7, r2
    mov r6, r3
    bl GetGlobalField0x1c020421a0
    mov r5, r0
    ldr r0, [r4]
    mov r1, r7
    mov r2, r6
    bl memcpy
    mov r0, r5
    mov r2, r8
    ldr r3, [r4]
    mov r1, #0xe3
    add r3, r3, r6
    str r3, [r4]
    str r1, [sp]
    mov r1, #0
    str r1, [sp, #4]
    mov r1, #1
    str r1, [sp, #8]
    mov r1, #0xc
    ldr r3, [r4]
    bl func_02046608
    ldr r0, [r4]
    bl strlen
    ldr r1, [r4]
    add r0, r1, r0
    str r0, [r4]
    add sp, sp, #0xc
    ldmia sp!, {r3, r4, r5, r6, r7, r8, pc}
}
