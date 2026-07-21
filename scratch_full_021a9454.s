func_ov017_021a9454: ; 0x021a9454
    stmdb sp!, {r3, r4, r5, r6, r7, lr}
    mov r6, r0
    bl _Z15GetBattleStructv
    mov r7, r0
    bl _Z26GetGlobalField0x1c020421a0v
    mov r5, r0
    bl func_02012fe4
    mov r0, r7
    bl _Z15GetFieldIfFlag4Pc
    ldr r1, [r6, #0x8]
    mov r4, r0
    cmp r1, #0x0
    bne .L_021a9520
    bl _Z25GetGlobalResetObj020d7a50v
    bl _Z29TeardownAndResetState020d7aa0P11Obj020d7aa0
    mov r0, r7
    bl _Z17GetPointerAt0x32cP20PointerField32c_ffc0
    bl _Z20ClearByteFlagAt0x154Ph
    ldr r0, [r6, #0x10]
    ldr r7, [r5, #0x5c]
    cmp r0, #0x0
    bne .L_021a94c4
    mov r0, #0x3a
    bl _Z28CallFunc020e0434With02153694i
    mov r1, r0
    mov r0, r7
    bl sprintf
    b .L_021a94e0
.L_021a94c4:
    mov r0, #0x3b
    bl _Z28CallFunc020e0434With02153694i
    mov r1, r0
    mov r0, r7
    bl sprintf
    ldr r0, .L_021a9628
    str r0, [r6, #0xc]
.L_021a94e0:
    mov r0, r5
    mov r1, r7
    mov r2, #0x0
    mov r3, #0xe3
    bl func_0204500c
    add r1, r5, #0x1000
    mov r2, #0x0
    strb r2, [r1, #0x9b2]
    mov r2, #0x1
    mov r0, r4
    mov r1, #0x2
    str r2, [r5, #0x998]
    bl _Z15SetFlagsAt0x244Phh
    mov r0, #0x1
    str r0, [r6, #0x8]
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
.L_021a9520:
    cmp r1, #0x1
    ldreq r1, [r5, #0x9a0]
    cmpeq r1, #0x0
    ldmneia sp!, {r3, r4, r5, r6, r7, pc}
    mov r1, #0x2
    bl _Z13ClearFlagBitsPhi
    mov r0, r5
    bl func_020457e0
    cmp r0, #0x0
    bne .L_021a9608
    mov r0, r7
    bl _Z17GetPointerAt0x32cP20PointerField32c_ffc0
    mov r0, r7
    bl _Z20GetField0x3f8AddressP12BattleStruct
    mov r1, #0x0
    mov r2, #0x70
    mov r4, r0
    bl VectorizedMemset
    mov r2, #0x1
    strb r2, [r4, #0x4]
    strb r2, [r4, #0x8]
    strb r2, [r4, #0x9]
    sub r0, r2, #0x2
    strb r0, [r4, #0xb]
    str r0, [r4, #0x20]
    str r0, [r4, #0x24]
    str r0, [r4, #0x28]
    str r0, [r4, #0x2c]
    strh r0, [r4, #0x1e]
    mov r1, #0x0
    strb r1, [r4, #0xc]
    strh r0, [r4, #0x6c]
    ldr r0, [r6, #0xc]
    strh r0, [r4, #0x0]
    strb r2, [r4, #0x2]
    strb r2, [r4, #0x7]
    ldr r0, [r6, #0x10]
    cmp r0, #0x0
    bne .L_021a95d4
    mov r0, #0x100000
    str r0, [r4, #0x10]
    str r1, [r4, #0x14]
    str r0, [r4, #0x18]
    strh r1, [r4, #0x1c]
    b .L_021a95f4
.L_021a95d4:
    ldr r1, .L_021a962c
    ldr r0, .L_021a9630
    str r1, [r4, #0x10]
    str r0, [r4, #0x14]
    mov r1, #0x570
    ldr r0, .L_021a9634
    str r1, [r4, #0x18]
    strh r0, [r4, #0x1c]
.L_021a95f4:
    mov r0, r5
    bl _Z24ReinitController02043204Pc
    mov r0, #0x1
    strb r0, [r6, #0x1]
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
.L_021a9608:
    mov r0, r5
    bl _Z24ReinitController02043204Pc
    mov r0, r7
    bl _Z17GetPointerAt0x32cP20PointerField32c_ffc0
    bl _Z18SetByteFlagAt0x154Ph
    mov r0, #0x1
    strb r0, [r6, #0x1]
    ldmia sp!, {r3, r4, r5, r6, r7, pc}
.L_021a9628: .word 0x170c
.L_021a962c: .word 0x5f0a
.L_021a9630: .word 0x3614
.L_021a9634: .word 0x4b66
    arm_func_end func_ov017_021a9454

    .global func_ov017_021a9638
    arm_func_start func_ov017_021a9638
