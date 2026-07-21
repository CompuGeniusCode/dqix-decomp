func_ov017_0219dc90: ; 0x0219dc90
    stmdb sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
    mov r10, r0
    mov r4, r1
    mov r9, r2
    mov r8, r3
    bl _Z15GetBattleStructv
    mov r11, r0
    bl func_0202ae18
    mov r5, r0
    bl _Z17GetEntryTableBasev
    mov r6, r0
    bl func_02012fe4
    mov r1, r4
    mov r0, r11
    bl _Z25GetCombatantWithFlag0x100P12BattleStructi
    mov r4, r0
    mov r0, r5
    bl _Z30GetSearchStructCurrentArrEntryP20SearchStruct0202c1a4
    cmp r0, #0x0
    ldmneia sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
    mov r0, r6
    bl func_020288e0
    mov r0, r10
    bl func_ov017_0219e0ec
    cmp r4, #0x0
    ldmeqia sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
    mov r0, r6
    mov r1, r9
    bl func_02028a54
    mov r5, r0
    mov r0, r10
    mov r1, r9
    bl func_ov017_0219e180
    mov r0, r6
    mov r1, r9
    bl _Z19FindInlineEntryByIdP14Entry_02028bd0i
    movs r6, r0
    add r0, r10, #0xb4
    add r7, r0, #0x4400
    beq .L_0219de54
    ldr r0, [r6, #0x34]
    cmp r0, #0x0
    moveq r0, #0x0
    beq .L_0219dd4c
    add r0, r6, #0x18
    add r1, r4, #0x44
    bl func_02028460
.L_0219dd4c:
    strh r0, [r4, #0xb8]
    mov r0, r11
    bl _Z15GetGrottoStructP12BattleStruct
    mov r11, r0
    mov r0, r9
    bl _Z17IsInRange0201b588i
    cmp r0, #0x0
    cmpne r5, #0x0
    ldrnesb r0, [r11, #0x8]
    strneb r0, [r6, #0xd]
    mov r0, #0x0
    str r0, [r6, #0x8]
    cmp r5, #0x0
    beq .L_0219de48
    ldrh r1, [r7, #0x0]
    cmp r1, r9
    bne .L_0219ddb4
    ldrh r2, [r7, #0x2]
    ldrh r3, [r6, #0x2]
    ldr r1, .L_0219de6c
    mov r2, r2, lsl #0x14
    and r1, r3, r1
    orr r1, r1, r2, lsr #0x10
    strh r1, [r6, #0x2]
    strh r0, [r7, #0x0]
    strh r0, [r7, #0x2]
.L_0219ddb4:
    ldrh r1, [r6, #0x2]
    add r0, r10, #0x29c
    add r2, r0, #0x3800
    mov r0, r1, lsl #0x1e
    mov r1, r0, lsr #0x1e
    mov r0, #0x18
    mla r4, r1, r0, r2
    ldrb r0, [r4, #0x2]
    cmp r0, #0x0
    mov r0, r4
    bne .L_0219de08
    bl func_ov017_021b46d8
    str r6, [r4, #0x8]
    ldrh r1, [sp, #0x28]
    strb r8, [r4, #0x11]
    add r0, r10, #0x3000
    strh r1, [r4, #0x12]
    ldr r0, [r0, #0x704]
    mov r1, r4
    bl _Z16AppendNodeToTailP16TailList020469b4P16TailNode020469b4
    b .L_0219de54
.L_0219de08:
    bl func_ov017_021b4760
    add r0, r10, #0x3000
    ldr r0, [r0, #0x704]
    mov r1, r4
    bl func_02046a8c
    mov r0, r4
    bl func_ov017_021b46d8
    str r6, [r4, #0x8]
    ldrh r1, [sp, #0x28]
    strb r8, [r4, #0x11]
    add r0, r10, #0x3000
    strh r1, [r4, #0x12]
    ldr r0, [r0, #0x704]
    mov r1, r4
    bl _Z16AppendNodeToTailP16TailList020469b4P16TailNode020469b4
    b .L_0219de54
.L_0219de48:
    ldrb r0, [r4, #0xc2]
    orr r0, r0, #0x40
    strb r0, [r4, #0xc2]
.L_0219de54:
    ldrh r0, [r7, #0x0]
    cmp r0, r9
    moveq r0, #0x0
    streqh r0, [r7, #0x0]
    streqh r0, [r7, #0x2]
    ldmia sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
.L_0219de6c: .word 0xffff000f
    arm_func_end func_ov017_0219dc90

    .global func_ov017_0219de70
    arm_func_start func_ov017_0219de70
