#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_0204673c
ARM asm char* FindNamedRecord0204673c(char* records, char* rawPath) {
    stmdb sp!, {r3, r4, r5, lr}
    movs r5, r0
    moveq r0, #0
    ldmeqia sp!, {r3, r4, r5, pc}
    cmp r1, #0
    moveq r0, #0
    ldmeqia sp!, {r3, r4, r5, pc}
    ldrsb r0, [r1]
    cmp r0, #0
    moveq r0, #0
    ldmeqia sp!, {r3, r4, r5, pc}
    mov r4, r1
    b path_test
path_loop:
    cmp r0, #0x2f
    addeq r4, r1, #1
    add r1, r1, #1
path_test:
    ldrsb r0, [r1]
    cmp r0, #0
    bne path_loop
    b record_test
record_loop:
    mov r0, r5
    mov r1, r4
    bl strcmp
    cmp r0, #0
    moveq r0, r5
    ldmeqia sp!, {r3, r4, r5, pc}
    ldr r0, [r5, #0x48]
    add r5, r5, r0
record_test:
    ldrsb r0, [r5]
    cmp r0, #0
    bne record_loop
    mov r0, #0
    ldmia sp!, {r3, r4, r5, pc}
}
