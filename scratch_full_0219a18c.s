func_ov017_0219a18c: ; 0x0219a18c
    stmdb sp!, {r3, r4, r5, r6, r7, r8, lr}
    sub sp, sp, #0xc
    mov r6, r0
    mov r4, #0x0
    b .L_0219a1bc
.L_0219a1a0:
    bl _Z15GetBattleStructv
    mov r1, r4
    bl _Z25GetCombatantWithFlag0x100P12BattleStructi
    cmp r0, #0x0
    beq .L_0219a1b8
    bl _Z26ProcessCombatState020534acPc
.L_0219a1b8:
    add r4, r4, #0x1
.L_0219a1bc:
    cmp r4, #0x4
    blt .L_0219a1a0
    add r0, r6, #0x4000
    ldr r1, [r0, #0x80]
    cmp r1, #0x0
    ldrne r1, [r0, #0x74]
    cmpne r1, #0x0
    beq .L_0219a368
    ldr r0, [r0, #0x78]
    cmp r0, #0x4
    blt .L_0219a368
    bl _Z15GetBattleStructv
    mov r4, r0
    bl _Z25GetCombatantAtField0x397cP12BattleStruct
    bl _Z16GetIntField0x260Pv
    mvn r1, #0x0
    cmp r0, r1
    bne .L_0219a368
    add r0, r6, #0xb4
    add r0, r0, #0x3c00
    mov r1, #0x2
    mov r2, #0x800
    bl _Z27FillEntriesEncoded_02199684P14Entry_02199684ii
    add r0, r6, #0x3000
    ldr r0, [r0, #0xcb0]
    bl _Z32ClearBuffers0204b010OverList0x98P12Cont0205d1e0
    add r0, r6, #0x3000
    ldr r0, [r0, #0xcb0]
    bl _Z28CallFunc0204c8f0OverList0x9cP12Cont0205d228
    add r0, r6, #0x3000
    mov r1, #0x1
    ldr r0, [r0, #0xcb0]
    mov r2, #0x2
    mov r3, r1
    bl func_0205da88
    mov r0, r4
    bl _Z24GetCombatantAtField0x3acP12BattleStruct
    mov r8, r0
    mov r0, r4
    bl _Z18GetField0x3acValueP12BattleStruct
    mov r1, r0
    mov r0, r4
    bl _Z25GetCombatantWithFlag0x100P12BattleStructi
    mov r7, r0
    mov r0, r8
    mov r8, #0x0
    bl _Z16GetIntField0x260Pv
    mov r4, r0
    mov r0, r7
    bl _Z25GetIndexedEntryField0x178Pa
    add r1, r4, #0x1
    cmp r1, #0x4
    addls pc, pc, r1, lsl #0x2
    b .L_0219a2d4
.L_0219a294: ; jump table
    b .L_0219a2d4 ; case 0
    b .L_0219a2a8 ; case 1
    b .L_0219a2b4 ; case 2
    b .L_0219a2c0 ; case 3
    b .L_0219a2cc ; case 4
.L_0219a2a8:
    mov r8, #0x1
    mov r5, #0x0
    b .L_0219a2d4
.L_0219a2b4:
    mov r8, #0x1
    mov r5, r8
    b .L_0219a2d4
.L_0219a2c0:
    mov r8, #0x1
    mov r5, #0x2
    b .L_0219a2d4
.L_0219a2cc:
    mov r8, #0x1
    mov r5, #0x3
.L_0219a2d4:
    cmp r8, #0x0
    beq .L_0219a32c
    cmp r0, #0x0
    blt .L_0219a32c
    add r0, r6, #0x3000
    ldr r0, [r0, #0xcb0]
    mov r1, r5
    bl _Z23FindElementByC40205d81cP15Struct_0205d81ci
    movs r4, r0
    beq .L_0219a32c
    ldrsh r1, [r4, #0xa8]
    add r0, r6, #0xb4
    mov r2, #0xf
    str r1, [sp, #0x0]
    ldrsh r3, [r4, #0xaa]
    add r0, r0, #0x3c00
    mov r1, #0x1
    str r3, [sp, #0x4]
    str r2, [sp, #0x8]
    ldrsh r2, [r4, #0xac]
    ldrsh r3, [r4, #0xae]
    bl func_0204bc74
.L_0219a32c:
    add r0, r6, #0x3000
    ldr r0, [r0, #0xcb0]
    bl _Z28CallFunc0204b04cOverList0x98P12Cont0205d274
    mov r0, r6
    mov r1, #0x10000
    bl _Z15GetBitsInField4Pjj
    cmp r0, #0x0
    bne .L_0219a358
    add r0, r6, #0x3000
    ldr r0, [r0, #0xcb0]
    bl _Z19InitEntries0205d2bcP11Obj0205d2bc
.L_0219a358:
    add r0, r6, #0xb4
    add r0, r0, #0x3c00
    mov r1, #0x2
    bl func_ov017_021996bc
.L_0219a368:
    add sp, sp, #0xc
    ldmia sp!, {r3, r4, r5, r6, r7, r8, pc}
    arm_func_end func_ov017_0219a18c

