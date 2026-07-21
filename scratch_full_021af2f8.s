func_ov017_021af2f8: ; 0x021af2f8
    stmdb sp!, {r3, r4, r5, r6, r7, r8, r9, lr}
    mov r9, r0
    bl _Z15GetBattleStructv
    bl func_ov017_0218b5b0
    mov r4, r0
    bl func_0202ae18
    mov r5, r0
    mov r1, #0x0
    bl _Z25GetEntryBySignedByteIndexP12SearchStructi
    bl _Z15GetData02100044v
    mov r6, r0
    mov r0, r5
    mov r1, #0x0
    bl _Z16TestFlagBitAt0xeP12SearchStructi
    cmp r0, #0x0
    bne .L_021af344
    bl _Z18GetGlobalField0x10v
    cmp r0, #0x8
    bne .L_021af378
.L_021af344:
    bl _Z27GetDataPtr02114e04_020d6c00v
    ldr r1, .L_021af4e4
    bl _Z18ClearFlags020466f4P16FlagWord020466f4j
    bl _Z17GetGlobal02109030v
    mov r4, r0
    bl _Z33ResetAndSetFlag0x3c9Bit0_020939dcPv
    mov r1, #0x4
    mov r0, r4
    sub r2, r1, #0x5
    mov r3, #0x0
    bl func_02094030
    mov r0, #0x3
    ldmia sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
.L_021af378:
    mov r0, r5
    mov r7, #0x0
    bl _Z30GetSearchStructCurrentArrEntryP20SearchStruct0202c1a4
    cmp r0, #0x0
    moveq r7, #0x1
    beq .L_021af408
    mov r8, r7
    b .L_021af3e8
.L_021af398:
    mov r0, r5
    bl _Z30GetSearchStructCurrentArrEntryP20SearchStruct0202c1a4
    cmp r8, r0
    beq .L_021af3e4
    mov r0, r5
    mov r1, r8
    bl _Z28TestMaskBitBySignedByteIndexP12SearchStructi
    cmp r0, #0x0
    beq .L_021af3e4
    mov r0, r5
    mov r1, r8
    bl _Z25GetEntryBySignedByteIndexP12SearchStructi
    cmp r0, #0x0
    beq .L_021af3e4
    ldrh r0, [r0, #0x2]
    mov r0, r0, lsl #0x1f
    movs r0, r0, lsr #0x1f
    moveq r7, #0x1
    beq .L_021af3f0
.L_021af3e4:
    add r8, r8, #0x1
.L_021af3e8:
    cmp r8, #0x4
    blt .L_021af398
.L_021af3f0:
    mov r0, r5
    bl _Z30GetSearchStructCurrentArrEntryP20SearchStruct0202c1a4
    ldrsb r1, [r9, #0x10]
    cmp r1, r0
    movne r0, #0x0
    strneb r0, [r9, #0xf]
.L_021af408:
    ldrsb r1, [r9, #0xf]
    mvn r0, #0x0
    cmp r1, r0
    beq .L_021af420
    cmp r7, #0x0
    beq .L_021af480
.L_021af420:
    ldr r0, .L_021af4e8
    mov r1, #0x2
    bl _Z25TestFlag0SetAndFlag1ClearPti
    cmp r0, #0x0
    beq .L_021af4dc
    mvn r2, #0x0
    mov r0, r4
    mov r1, #0x2
    strb r2, [r9, #0xf]
    bl _Z13SetBitsInWordPjj
    mov r0, r5
    bl func_0202b0f4
    mov r0, r4
    bl _Z29ClearTwoBytesAtField_02195748Ph
    mov r0, r4
    bl func_ov017_02192594
    mov r0, r6
    bl _Z24FillBitArray0x1524WithFFP19BitArrayObj0205e854
    mov r0, r4
    mov r1, #0x40
    bl _Z15ClearBitsInWordPjj
    mov r0, #0x1
    strb r0, [r9, #0x1]
    b .L_021af4dc
.L_021af480:
    cmp r1, #0x1
    bne .L_021af49c
    ldr r0, [r5, #0xfc0]
    cmp r0, #0x0
    moveq r0, #0x1
    streqb r0, [r9, #0x1]
    b .L_021af4dc
.L_021af49c:
    mov r0, r4
    mov r1, #0x2
    bl _Z13SetBitsInWordPjj
    mov r0, r5
    bl func_0202b0f4
    mov r0, r4
    bl _Z29ClearTwoBytesAtField_02195748Ph
    mov r0, r4
    bl func_ov017_02192594
    mov r0, r6
    bl _Z24FillBitArray0x1524WithFFP19BitArrayObj0205e854
    mov r0, r4
    mov r1, #0x40
    bl _Z15ClearBitsInWordPjj
    mov r0, #0x1
    strb r0, [r9, #0x1]
.L_021af4dc:
    ldrb r0, [r9, #0x8]
    ldmia sp!, {r3, r4, r5, r6, r7, r8, r9, pc}
.L_021af4e4: .word 0x8020
.L_021af4e8: .word data_02114e30
    arm_func_end func_ov017_021af2f8

    .global func_ov017_021af4ec
    arm_func_start func_ov017_021af4ec
