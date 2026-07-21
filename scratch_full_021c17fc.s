func_ov017_021c17fc: ; 0x021c17fc
    stmdb sp!, {r4, r5, r6, r7, r8, lr}
    mov r8, r0
    bl _Z15GetBattleStructv
    mov r7, r0
    bl func_ov017_0218b5b0
    mov r6, r0
    mov r0, r7
    bl _Z25GetCombatantAtField0x397cP12BattleStruct
    mov r1, #0x1
    mov r5, r0
    bl _Z27CancelPendingAction020397ccP11Obj020397cci
    mov r0, r6
    mov r1, #0xc0
    bl _Z15SetBitsInField4Pjj
    mov r0, r7
    bl _Z15GetFieldIfFlag4Pc
    mov r4, r0
    mov r1, #0x3
    bl _Z15SetFlagsAt0x244Phh
    ldrb r0, [r8, #0x1c]
    cmp r0, #0x0
    bne .L_021c18e8
    ldr r0, .L_021c19d4
    bl func_020a0cc4
    ldr r0, .L_021c19d8
    ldr r1, .L_021c19d4
    bl _Z16AllocateAligned4P14AllocatorUnionj
    movs r1, r0
    bne .L_021c1880
    bl func_020a0c0c
    mov r0, #0x1
    strb r0, [r8, #0x1]
    ldmia sp!, {r4, r5, r6, r7, r8, pc}
.L_021c1880:
    ldr r2, .L_021c19d4
    add r0, r8, #0x8
    bl _ZN13SafeAllocator11CreateTypeAEPvj
    add r0, r8, #0x8
    bl _ZN13SafeAllocator5ResetEv
    ldrb r0, [r8, #0x1d]
    cmp r0, #0x0
    beq .L_021c18a8
    mov r0, #0x3
    bl _Z13PushInputLogAi
.L_021c18a8:
    ldr r0, .L_021c19dc
    bl func_020a1940
    mov r0, #0x1
    bl _Z13PushInputLogBi
    add r0, r8, #0x8
    mov r1, #0x14c0
    bl _ZN13SafeAllocator8AllocateEj
    str r0, [r8, #0x20]
    bl func_ov012_021843d4
    ldr r0, [r8, #0x20]
    add r1, r8, #0x8
    bl func_ov012_02184884
    ldrb r0, [r8, #0x1c]
    add r0, r0, #0x1
    strb r0, [r8, #0x1c]
    ldmia sp!, {r4, r5, r6, r7, r8, pc}
.L_021c18e8:
    cmp r0, #0x1
    bne .L_021c1918
    mov r0, r7
    bl _Z19GetBattleScaleCountP12BattleStruct
    mov r1, r0
    ldr r0, [r8, #0x20]
    bl func_ov012_02184acc
    cmp r0, #0x0
    ldrneb r0, [r8, #0x1c]
    addne r0, r0, #0x1
    strneb r0, [r8, #0x1c]
    ldmia sp!, {r4, r5, r6, r7, r8, pc}
.L_021c1918:
    cmp r0, #0x2
    bne .L_021c1938
    ldr r0, [r8, #0x20]
    bl func_ov012_02185af0
    ldrb r0, [r8, #0x1c]
    add r0, r0, #0x1
    strb r0, [r8, #0x1c]
    ldmia sp!, {r4, r5, r6, r7, r8, pc}
.L_021c1938:
    cmp r0, #0x3
    ldmneia sp!, {r4, r5, r6, r7, r8, pc}
    ldr r3, [r8, #0x20]
    mov r2, #0x4000000
    add r0, r3, #0x1000
    ldr r1, [r2, #0x0]
    ldrb r7, [r0, #0x4bc]
    ldr r3, [r3, #0x1c]
    bic r0, r1, #0x1f00
    orr r1, r0, r3, lsl #0x8
    mov r0, r8
    str r1, [r2, #0x0]
    bl func_ov017_021c1a24
    mov r0, #0x0
    bl _Z29SetCombatModeFromCase020dc2d0i
    ldrb r0, [r8, #0x1d]
    cmp r0, #0x0
    beq .L_021c19b8
    cmp r7, #0x0
    beq .L_021c19ac
    mov r0, r5
    bl _Z17SetByteField0x253Pv
    mov r0, r4
    mov r1, #0x3
    bl _Z13ClearFlagBitsPhi
    mov r0, r6
    mov r1, #0xc0
    bl _Z17ClearBitsInField4Pjj
    b .L_021c19c4
.L_021c19ac:
    mov r0, r6
    bl func_ov017_021a5530
    b .L_021c19c4
.L_021c19b8:
    mov r0, r6
    mov r1, #0x1
    bl func_ov017_0218d77c
.L_021c19c4:
    bl func_020a0c0c
    mov r0, #0x1
    strb r0, [r8, #0x1]
    ldmia sp!, {r4, r5, r6, r7, r8, pc}
.L_021c19d4: .word 0x2e4c0
.L_021c19d8: .word data_02114e20
.L_021c19dc: .word 0xc
    arm_func_end func_ov017_021c17fc

