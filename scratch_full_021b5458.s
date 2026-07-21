func_ov017_021b5458: ; 0x021b5458
    stmdb sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
    sub sp, sp, #0x90
    mov r4, r0
    bl _Z15GetBattleStructv
    bl _Z21GetData02104304Field4v
    mov r6, r0
    bl func_0202ae18
    ldr r1, [r4, #0xc]
    mov r0, r6
    bl func_0202fdd0
    cmp r0, #0x0
    beq .L_021b5640
    ldr r1, [r4, #0xc]
    mov r0, r6
    bl _Z20LookupListValueByKeyP12List0202fe68i
    cmp r0, #0x2
    bne .L_021b5624
    ldr r1, [r4, #0xc]
    add r2, sp, #0x8
    add r3, sp, #0xc
    mov r0, r6
    bl _Z26GetListEntryValues0202fec8P12List0202fec8iPiS1_
    ldr r0, [sp, #0x8]
    cmp r0, #0x0
    beq .L_021b5624
    add r0, sp, #0x10
    mov r1, #0x80
    bl func_0200f374
    mov r7, #0x0
    mov r8, r7
    ldr r5, [r4, #0x8]
    b .L_021b55f0
.L_021b54d8:
    mov r1, r8
    add r0, r5, #0x124
    bl _Z13GetRowByIndexP16GetRowByIndexRowi
    cmp r0, #0x0
    beq .L_021b55ec
    mov r2, #0x0
    add r10, sp, #0x10
    mov r1, #0x1
    mov r11, r2
    b .L_021b5560
.L_021b5500:
    add r3, r0, r2, lsl #0x3
    ldr r3, [r3, #0x4]
    mov ip, r1
    mov r3, r3, lsl #0x14
    mov lr, r11
    mov r3, r3, lsr #0x14
    b .L_021b5534
.L_021b551c:
    mov r9, lr, lsl #0x1
    ldrsh r9, [r10, r9]
    cmp r3, r9
    moveq ip, #0x0
    beq .L_021b553c
    add lr, lr, #0x1
.L_021b5534:
    cmp lr, r7
    blt .L_021b551c
.L_021b553c:
    cmp ip, #0x0
    beq .L_021b555c
    mov r9, r7
    add r7, r7, #0x1
    mov r7, r7, lsl #0x10
    mov r7, r7, asr #0x10
    mov r9, r9, lsl #0x1
    strh r3, [r10, r9]
.L_021b555c:
    add r2, r2, #0x1
.L_021b5560:
    ldrb r3, [r0, #0x2]
    cmp r2, r3
    blt .L_021b5500
    mov r2, #0x0
    add ip, sp, #0x10
    mov r1, #0x1
    mov lr, r2
    b .L_021b55e0
.L_021b5580:
    add r3, r0, r2, lsl #0x2
    ldr r3, [r3, #0x34]
    mov r9, r1
    mov r3, r3, lsl #0x14
    mov r10, lr
    mov r3, r3, lsr #0x14
    b .L_021b55b4
.L_021b559c:
    mov r11, r10, lsl #0x1
    ldrsh r11, [ip, r11]
    cmp r3, r11
    moveq r9, #0x0
    beq .L_021b55bc
    add r10, r10, #0x1
.L_021b55b4:
    cmp r10, r7
    blt .L_021b559c
.L_021b55bc:
    cmp r9, #0x0
    beq .L_021b55dc
    mov r9, r7
    add r7, r7, #0x1
    mov r7, r7, lsl #0x10
    mov r7, r7, asr #0x10
    mov r9, r9, lsl #0x1
    strh r3, [ip, r9]
.L_021b55dc:
    add r2, r2, #0x1
.L_021b55e0:
    ldrb r3, [r0, #0x3]
    cmp r2, r3
    blt .L_021b5580
.L_021b55ec:
    add r8, r8, #0x1
.L_021b55f0:
    cmp r8, #0x6
    blt .L_021b54d8
    ldr r5, [r4, #0x8]
    add r0, r5, #0x30c
    bl _Z20Clear12Bytes020a8e88Pv
    add r1, sp, #0x10
    stmia sp, {r1, r7}
    ldr r1, [r4, #0x8]
    ldr r2, [sp, #0x8]
    ldr r1, [r1, #0x10]
    ldr r3, [sp, #0xc]
    add r0, r5, #0x30c
    bl func_020a8fd0
.L_021b5624:
    ldr r1, [r4, #0xc]
    mov r0, r6
    bl func_020301c8
    mvn r1, #0x0
    mov r0, r4
    str r1, [r4, #0xc]
    bl func_ov017_021b5648
.L_021b5640:
    add sp, sp, #0x90
    ldmia sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
    arm_func_end func_ov017_021b5458

    .global func_ov017_021b5648
    arm_func_start func_ov017_021b5648
