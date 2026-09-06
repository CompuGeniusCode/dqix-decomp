func_ov017_021a63d0: ; 0x021a63d0
    stmdb sp!, {r4, r5, r6, r7, r8, r9, lr}
    sub sp, sp, #0xc
    mov r9, r0
    add r0, r9, #0x4000
    ldr r1, [r0, #0x1c0]
    cmp r1, #0x0
    ldrne r0, [r0, #0x1b4]
    cmpne r0, #0x0
    beq .L_021a65b8
    bl func_0202ae18
    mov r8, r0
    bl _Z15GetBattleStructv
    bl _Z24GetCombatantAtField0x3acP12BattleStruct
    bl _Z16GetIntField0x260Pv
    mov r7, r0
    bl _Z26GetGlobalField0x1c020421a0v
    mov r6, r0
    bl func_02012fe4
    mov r5, r0
    bl _Z24GetGlobalContext020daf90v
    mov r4, r0
    bl _Z15GetBattleStructv
    bl _Z15GetGrottoStructP12BattleStruct
    ldrb r0, [r0, #0x0]
    cmp r0, #0x0
    beq .L_021a65b8
    add r0, r9, #0x4000
    ldr r0, [r0, #0x80]
    cmp r0, #0x0
    mvneq r0, #0x0
    cmpeq r7, r0
    bne .L_021a65b8
    add r0, r9, #0x3000
    ldr r0, [r0, #0x6fc]
    bl _Z12IsField0NullPPv
    cmp r0, #0x0
    beq .L_021a65b8
    mov r0, r8
    bl func_0202c540
    cmp r0, #0x0
    bne .L_021a65b8
    bl _Z15GetBattleStructv
    bl _Z18IsGlobalU16InRangev
    cmp r0, #0x0
    ldreq r0, [r6, #0x998]
    cmpeq r0, #0x0
    bne .L_021a65b8
    mov r0, r5
    bl _Z30CheckSlotsForFlagState02015a2cP17Something02015a2c
    cmp r0, #0x0
    bne .L_021a65b8
    mov r0, r4
    bl _Z12GetField0x50Pv
    cmp r0, #0x0
    bne .L_021a65b8
    add r0, r9, #0x94
    add r0, r0, #0x4000
    mov r1, #0x2
    mov r2, #0x800
    bl _Z29FillFieldWithEncoded_021a5ad0P17Node0x20_021a5ad0ii
    ldr r3, .L_021a65c0
    add r2, sp, #0x0
    mov r1, #0x5
.L_021a64cc:
    ldrh r0, [r3], #0x2
    subs r1, r1, #0x1
    strh r0, [r2], #0x2
    bne .L_021a64cc
    bl _Z15GetBattleStructv
    bl _Z24NormalizeField5_0200fb08P14Struct0200fb08
    add r1, r9, #0x4000
    ldr r2, [r1, #0x1b8]
    mov r4, r0
    cmp r2, #0x3
    blt .L_021a65a8
    ldr r5, [r1, #0x90]
    mov r0, r5
    bl _Z32ClearBuffers0204b010OverList0x98P12Cont0205d1e0
    mov r0, r5
    bl _Z28CallFunc0204c8f0OverList0x9cP12Cont0205d228
    mov r1, #0x1
    mov r0, r5
    mov r3, r1
    mov r2, #0x2
    bl func_0205da88
    mov r0, r5
    bl _Z28CallFunc0204b04cOverList0x98P12Cont0205d274
    mov r0, r5
    bl _Z19InitEntries0205d2bcP11Obj0205d2bc
    add r0, r9, #0x4000
    ldr r0, [r0, #0x1c4]
    mov r1, #0x0
    ldr r2, [r0, #0x40]
    cmp r2, #0x0
    beq .L_021a6554
    ldrh r0, [r0, #0x4e]
    cmp r0, #0x6
    addhi r1, r2, #0xf0
.L_021a6554:
    cmp r1, #0x0
    beq .L_021a65a8
    sub r2, r4, #0x1
    add r0, sp, #0x0
    mov r2, r2, lsl #0x1
    ldrsh r3, [r0, r2]
    mov r2, #0xab000
    mov r0, #0x7e
    add r3, r3, #0x7
    mov r3, r3, lsl #0xc
    str r3, [r1, #0x14]
    str r2, [r1, #0x18]
    strb r0, [r1, #0x22]
    mov r0, #0x0
    strb r0, [r1, #0x26]
    mov r0, #0x1000
    str r0, [r1, #0xc]
    str r0, [r1, #0x10]
    add r0, r9, #0x4000
    ldr r0, [r0, #0x1c4]
    bl func_0205ac40
.L_021a65a8:
    add r0, r9, #0x94
    add r0, r0, #0x4000
    mov r1, #0x2
    bl func_ov017_021a5b08
.L_021a65b8:
    add sp, sp, #0xc
    ldmia sp!, {r4, r5, r6, r7, r8, r9, pc}
.L_021a65c0: .word data_ov017_021d6a9e
    arm_func_end func_ov017_021a63d0

    .global func_ov017_021a65c4
    arm_func_start func_ov017_021a65c4
