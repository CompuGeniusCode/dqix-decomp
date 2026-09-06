func_ov017_021bf7ac: ; 0x021bf7ac
    stmdb sp!, {r3, r4, r5, r6, r7, r8, r9, r10, lr}
    sub sp, sp, #0xa4
    mov r8, r0
    bl _Z15GetBattleStructv
    mov r6, r0
    bl _Z25GetCombatantAtField0x397cP12BattleStruct
    bl func_02012fe4
    ldr r4, [r8, #0xc]
    mov r5, r0
    bl _Z21GetData02104304Field4v
    ldrh r9, [r4, #0x2c]
    ldrh r10, [r4, #0x2e]
    mov r7, r0
    mov r0, r5
    mov r1, r9
    mov r2, r10
    bl _Z25ClearAndFlagEntry0201ba1cP12Base02019508ii
    ldrh r0, [r5, #0x0]
    mov r1, r9
    mov r2, r10
    bl func_ov017_021cfe40
    bl _Z15GetData02108e90v
    mov r9, r0
    bl func_0205ec34
    mov r5, r0
    cmp r9, #0x0
    cmpne r5, #0x0
    moveq r0, #0x3
    beq .L_021bf988
    mov r0, #0x0
    strh r0, [sp, #0x0]
    ldrh r1, [r4, #0x30]
    add r2, sp, #0x0
    mov r0, r9
    bl _Z21FindNodeByIdWithIndexP8ContBFD8tPt
    movs r4, r0
    beq .L_021bf97c
    ldrh r2, [r4, #0x0]
    mov r0, r5
    add r1, r5, #0x8c
    add r2, r2, #0x9e
    add r2, r2, #0x700
    bl _Z18TestBitInByteArrayiPhi
    cmp r0, #0x0
    bne .L_021bf97c
    bl func_02012fe4
    mov r9, r0
    mov r0, r6
    add r5, r9, #0x354
    bl _Z18GetField0x3acValueP12BattleStruct
    add r2, r9, #0x600
    mov r1, #0x88
    mla r1, r0, r1, r2
    mov r0, r1
    str r1, [r8, #0x10]
    bl _Z19MaybeInvoke0204719cP14Struct02047230
    ldrh r0, [r4, #0x4]
    mov r0, r0, lsl #0x1c
    mov r0, r0, lsr #0x1e
    cmp r0, #0x1
    bne .L_021bf8d4
    ldr r3, .L_021bf990
    add r2, sp, #0x2
    mov r1, #0x20
.L_021bf8ac:
    ldrb r0, [r3], #0x1
    subs r1, r1, #0x1
    strb r0, [r2], #0x1
    bne .L_021bf8ac
    add r1, sp, #0x2
    mov r0, r7
    mov r2, #0x0
    bl _Z23CallFunc0202fa38ZeroPadiii
    strh r0, [r8, #0x14]
    b .L_021bf97c
.L_021bf8d4:
    ldrsh r1, [r4, #0x2]
    add r0, r5, #0x2400
    bl _Z24FindElementByKey020dedd0P17Container020dedd0i
    movs r4, r0
    beq .L_021bf97c
    ldrsh r2, [r4, #0x18]
    ldr r1, .L_021bf994
    cmp r2, r1
    bne .L_021bf93c
    mov r1, #0x1
    add r0, r8, #0x4c
    strb r1, [r8, #0x48]
    bl _ZN13SafeAllocator21ResetAllocatorPointerEv
    ldr r0, .L_021bf998
    mov r1, #0x4000
    bl _Z16AllocateAligned4P14AllocatorUnionj
    mov r1, r0
    add r0, r8, #0x4c
    mov r2, #0x4000
    bl _ZN13SafeAllocator11CreateTypeAEPvj
    add r0, r8, #0x4c
    bl _ZN13SafeAllocator5ResetEv
    bl func_ov017_0218b5b0
    add r1, r8, #0x4c
    bl func_ov017_0218d510
    b .L_021bf97c
.L_021bf93c:
    mov r1, #0x0
    bl _Z31GetPreferredPackedField020de234P20StructDE234_020de234i
    ldr r1, [r4, #0x10]
    mov r3, r0
    mov r0, r1, lsl #0x4
    mov r0, r0, lsr #0x18
    mov r2, r0, lsl #0x18
    ldr r1, .L_021bf99c
    add r0, sp, #0x22
    mov r2, r2, asr #0x18
    bl sprintf
    add r1, sp, #0x22
    mov r0, r7
    mov r2, #0x0
    bl _Z23CallFunc0202fa38ZeroPadiii
    strh r0, [r8, #0x14]
.L_021bf97c:
    mov r0, #0x12c
    strh r0, [r8, #0x8]
    mov r0, #0x3
.L_021bf988:
    add sp, sp, #0xa4
    ldmia sp!, {r3, r4, r5, r6, r7, r8, r9, r10, pc}
.L_021bf990: .word data_ov017_021d6ca4
.L_021bf994: .word 0x5617
.L_021bf998: .word data_02114e20
.L_021bf99c: .word data_ov017_021d7ee8
    arm_func_end func_ov017_021bf7ac

    .global func_ov017_021bf9a0
    arm_func_start func_ov017_021bf9a0
