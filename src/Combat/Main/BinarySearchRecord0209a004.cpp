#include <globaldefs.h>
int GetShortAt0x28(struct ShortField0x28_02099fe8* obj);
// USA: func_0209a004
ARM asm void* BinarySearchRecord0209a004(void* list, int key) {
    stmdb sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    ldr r6, [r0, #4]
    mov r7, r1
    cmp r6, #0
    ldrne r1, =GetShortAt0x28
    cmpne r1, #0
    moveq r9, #0
    beq done
    ldr r0, [r0]
    mov r0, r0, lsl #20
    movs r0, r0, lsr #20
    moveq r9, #0
    beq done
    sub r4, r0, #1
    mov r5, #0
    mov r8, #0x2c
    b test
loop:
    sub r0, r4, r5
    add r0, r0, #1
    add r10, r5, r0, asr #1
    mla r9, r10, r8, r6
    mov r0, r9
    bl GetShortAt0x28
    cmp r0, r7
    beq done
    subgt r4, r10, #1
    addle r5, r10, #1
test:
    cmp r5, r4
    ble loop
    mov r9, #0
done:
    mov r0, r9
    ldmia sp!, {r4, r5, r6, r7, r8, r9, r10, pc}
}
