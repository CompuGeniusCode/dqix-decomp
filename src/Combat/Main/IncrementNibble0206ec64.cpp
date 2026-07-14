#include <globaldefs.h>
void InsertShortIntoTable021098f4(unsigned short value);
// USA: func_0206ec64
ARM asm void IncrementNibble0206ec64(int unused, int index, unsigned char* data, unsigned int count) {
    stmdb sp!, {r3, lr}
    mov ip, r1, lsr #31
    add lr, r1, r1, lsr #31
    rsb r0, ip, r1, lsl #31
    cmp r3, lr, asr #1
    add r1, ip, r0, ror #31
    mov r0, lr, asr #1
    bhi valid
    ldr r0, =0x3e7
    bl InsertShortIntoTable021098f4
    ldmia sp!, {r3, pc}
valid:
    cmp r1, #0
    ldrb ip, [r2, r0]
    beq high
    and r1, ip, #0xf
    cmp r1, #0xf
    ldmhsia sp!, {r3, pc}
    add r1, r1, #1
    and r3, r1, #0xff
    and r1, ip, #0xf0
    orr r1, r3, r1
    strb r1, [r2, r0]
    ldmia sp!, {r3, pc}
high:
    mov r1, ip, asr #4
    and r1, r1, #0xff
    cmp r1, #0xf
    addlo r1, r1, #1
    andlo r3, r1, #0xff
    andlo r1, ip, #0xf
    orrlo r1, r1, r3, lsl #4
    strlob r1, [r2, r0]
    ldmia sp!, {r3, pc}
}
