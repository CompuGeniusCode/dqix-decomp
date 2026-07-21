func_ov017_021b478c: ; 0x021b478c
    stmdb sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
    sub sp, sp, #0xb8
    mov r10, r0
    bl _Z15GetBattleStructv
    mov r11, r0
    bl _Z21GetData02104304Field4v
    mov r6, r0
    mov r0, r11
    bl _Z16GetPtrField0x468Pv
    mov r4, r0
    bl func_02012fe4
    mov r5, r0
    mov r0, r4
    add r1, r5, #0x3ec
    add r9, r1, #0x2000
    ldr r1, [r10, #0x8]
    ldrh r7, [r1, #0x0]
    mov r1, r7
    bl _Z22FindEntryByHalfwordKeyP11SearchTablei
    mov r4, r0
    ldr r8, [r10, #0x8]
    add r0, r8, #0x44
    bl _Z17ClearHalfword0x18Pv
    add r0, r8, #0x60
    bl _Z19ClearBuffer0209bc84Pv
    add r0, r8, #0x124
    bl _Z19ResetObject0209af34P25ResetObject0209af34Struct
    add r0, r8, #0x2f8
    bl _Z20Clear12Bytes0206efc4Pv
    add r0, r8, #0x304
    bl _Z23ZeroWordAndByte0206ee60P29ZeroWordAndByte0206ee60Struct
    add r0, r8, #0x30c
    bl _Z20Clear12Bytes020a8e88Pv
    ldr r1, [r10, #0x8]
    ldrh r0, [r1, #0x0]
    cmp r0, #0x3
    beq .L_021b4830
    ldr r0, [r1, #0x10]
    bl _ZNK13SafeAllocator18GetSignedAllocatorEv
    cmp r0, #0x0
    bne .L_021b483c
.L_021b4830:
    mov r0, #0x1
    strb r0, [r10, #0x1]
    b .L_021b4970
.L_021b483c:
    mov r0, r7
    bl _Z17IsInRange0201b5b0i
    cmp r0, #0x0
    bne .L_021b48b4
    add r0, r4, #0x5
    bl strlen
    cmp r0, #0x6
    add r0, sp, #0x4
    bhs .L_021b4870
    ldr r1, .L_021b4978
    add r2, r4, #0x5
    bl sprintf
    b .L_021b487c
.L_021b4870:
    ldr r1, .L_021b497c
    add r2, r4, #0x5
    bl sprintf
.L_021b487c:
    mov r2, #0x50
    add r0, sp, #0x68
    add r1, sp, #0x4
    strb r2, [sp, #0x7]
    bl strcpy
    ldr r1, .L_021b4980
    add r2, sp, #0x68
    mov r0, r6
    mov r3, #0x0
    bl _Z21CallFunc0202fa38Mode2iiii
    str r0, [r10, #0xc]
    mov r0, #0x1
    strb r0, [r10, #0x10]
    b .L_021b4970
.L_021b48b4:
    mov r0, r11
    bl _Z24GetCombatantAtField0x3acP12BattleStruct
    bl _Z11GetU16At0x6P20U16Field0x6_020375f8
    cmp r7, r0
    beq .L_021b4900
    mov r0, r9
    bl _ZNK17ActiveGrottoClass22GetActiveGrottoEnvironEv
    mov r2, r0
    ldr r1, .L_021b4984
    add r0, sp, #0x18
    bl sprintf
    add r1, sp, #0x18
    mov r0, r6
    mov r2, #0x0
    bl _Z23CallFunc0202fa38ZeroPadiii
    str r0, [r10, #0xc]
    mov r0, #0x2
    strb r0, [r10, #0x10]
    b .L_021b4970
.L_021b4900:
    mov r0, r7
    bl _Z17IsInRange0201b5b0i
    cmp r0, #0x0
    beq .L_021b4948
    mov r0, r7
    mov r1, #0x14
    bl _s32_div_f
    ldr r0, [r9, #0x1c8]
    cmp r0, #0x0
    beq .L_021b4970
    ldr r0, [r5, #0x424]
    cmp r0, #0x0
    bne .L_021b4970
    mov r3, #0x0
    str r3, [sp, #0x0]
    ldr r2, [r10, #0x8]
    mov r0, r5
    bl func_0201a300
.L_021b4948:
    ldr r3, [r10, #0x8]
    mov r4, #0x1
    ldr r1, .L_021b4988
    mov r0, r6
    mov r2, #0x0
    strb r4, [r3, #0xc]
    bl _Z23CallFunc0202fa38ZeroPadiii
    str r0, [r10, #0xc]
    mov r0, #0x3
    strb r0, [r10, #0x10]
.L_021b4970:
    add sp, sp, #0xb8
    ldmia sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
.L_021b4978: .word data_ov017_021d7afc
.L_021b497c: .word data_ov017_021d7b06
.L_021b4980: .word data_ov017_021d7b0d
.L_021b4984: .word data_ov017_021d7b24
.L_021b4988: .word data_ov017_021d7b3a
    arm_func_end func_ov017_021b478c

    .global func_ov017_021b498c
    arm_func_start func_ov017_021b498c
