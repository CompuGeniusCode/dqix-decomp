#include <globaldefs.h>

int GetRandomUpTo02032370(int max);

// USA: func_02073fdc
ARM asm int SelectWeightedEntry02073fdc(void* obj) {
    stmdb sp!, {r3, r4, r5, lr}
    mov r4, r0
    mov r0, #0
    mov r2, r0
    b sum_test
sum_loop:
    add r1, r4, r2, lsl #2
    ldrh r1, [r1, #8]
    add r2, r2, #1
    mov r1, r1, lsl #17
    add r0, r0, r1, lsr #29
sum_test:
    ldrh r1, [r4, #2]
    cmp r2, r1
    blt sum_loop
    bl GetRandomUpTo02032370
    mov lr, #0
    mov r5, lr
    mvn ip, #0
    add r3, r4, #8
    b find_test
find_loop:
    mov r1, r5, lsl #2
    ldrh r1, [r3, r1]
    mov r2, r1, lsl #17
    add lr, lr, r2, lsr #29
    cmp r0, lr
    movlt r0, r1, lsl #20
    movlt ip, r0, lsr #20
    blt done
    add r5, r5, #1
find_test:
    ldrh r1, [r4, #2]
    cmp r5, r1
    blt find_loop
done:
    mov r0, ip
    ldmia sp!, {r3, r4, r5, pc}
}
