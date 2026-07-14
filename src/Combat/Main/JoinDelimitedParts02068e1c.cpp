#include <globaldefs.h>
#include "std_library_functions.h"
int StringLength(const char* s);
// USA: func_02068e1c
ARM asm char* JoinDelimitedParts02068e1c(char* dst, char* first, char* second, char* third) {
    stmdb sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
    mov r4, r0
    mov r9, r1
    mov r5, r2
    mov r8, r3
    bl strstr
    movs r6, r0
    beq done
    mov r1, r5
    bl strstr
    movs r7, r0
    beq done
    mov r1, r8
    bl strstr
    movs r5, r0
    beq done
    mov r0, r9
    bl StringLength
    add r4, r6, r0
    mov r0, r8
    bl StringLength
    mov r2, r4
    mov r3, r4
copy_loop:
    cmp r3, r7
    addeq r3, r5, r0
    ldrsb r1, [r3]
    cmp r1, #0
    strb r1, [r2]
    addne r2, r2, #1
    addne r3, r3, #1
    bne copy_loop
done:
    mov r0, r4
    ldmia sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
}
