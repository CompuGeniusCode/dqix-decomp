func_ov017_02199780: ; 0x02199780
    stmdb sp!, {r3, r4, r5, lr}
    mov r5, r0
    add r0, r5, #0x4000
    ldr r1, [r0, #0x80]
    cmp r1, #0x0
    ldmeqia sp!, {r3, r4, r5, pc}
    ldr r1, [r0, #0x78]
    cmp r1, #0x0
    beq .L_02199954
    mov r2, #0x4000000
    ldr r1, [r2, #0x0]
    bic r1, r1, #0x1f00
    orr r1, r1, #0x100
    str r1, [r2, #0x0]
    ldr r0, [r0, #0x7c]
    cmp r0, #0x0
    blt .L_021997d4
    bl _Z21GetData02104304Field4v
    add r1, r5, #0x4000
    ldr r1, [r1, #0x7c]
    bl func_020301c8
.L_021997d4:
    ldr r0, .L_02199960
    mov r1, #0x0
    strh r1, [r0, #0x0]
    sub r2, r0, #0x48
    ldrh r1, [r2, #0x0]
    add r0, r5, #0x3000
    bic r1, r1, #0x3
    orr r1, r1, #0x1
    strh r1, [r2, #0x0]
    ldr r4, [r0, #0xca8]
    ldrh r0, [r4, #0x0]
    mov r0, r0, lsl #0x12
    mov r0, r0, lsr #0x1f
    str r0, [sp, #0x0]
    ldrh r0, [r4, #0x0]
    mov ip, r0, lsl #0x10
    mov r1, r0, lsl #0x18
    mov r2, r0, lsl #0x13
    mov r3, r0, lsl #0x1a
    mov r0, ip, lsr #0x1e
    mov r1, r1, lsr #0x1f
    mov r2, r2, lsr #0x1b
    mov r3, r3, lsr #0x1c
    bl _Z26SetBg1ControlBits_02199964iiiii
    ldrh r0, [r4, #0x0]
    mov r0, r0, lsl #0x1e
    mov r0, r0, lsr #0x1e
    bl _Z26SetBg1CntPriority_02199998i
    add r0, r5, #0x3000
    ldr r4, [r0, #0xcac]
    ldrh r3, [r4, #0x0]
    mov r0, r3, lsl #0x10
    mov r1, r3, lsl #0x18
    mov r2, r3, lsl #0x13
    mov r0, r0, lsr #0x1e
    mov r1, r1, lsr #0x1f
    mov r2, r2, lsr #0x1b
    mov r3, r3, lsl #0x1a
    mov r3, r3, lsr #0x1c
    bl _Z22SetBg2CntFull_021999b4iiii
    ldrh r0, [r4, #0x0]
    mov r0, r0, lsl #0x1e
    mov r0, r0, lsr #0x1e
    bl _Z26SetBg2CntPriority_021999e0i
    add r0, r5, #0x4000
    ldr r0, [r0, #0x84]
    cmp r0, #0x0
    beq .L_021998a4
    bl _Z22ResetAndDetach020dfc6cP14Struct020dfc40
    add r0, r5, #0x4000
    mov r1, #0x0
    str r1, [r0, #0x84]
.L_021998a4:
    add r0, r5, #0x4000
    ldr r0, [r0, #0x74]
    cmp r0, #0x0
    beq .L_02199940
    add r0, r5, #0xb4
    add r0, r0, #0x3c00
    mov r1, #0x2
    mov r2, #0x800
    bl _Z27FillEntriesEncoded_02199684P14Entry_02199684ii
    add r0, r5, #0x3000
    ldr r0, [r0, #0xcb0]
    bl _Z32ClearBuffers0204b010OverList0x98P12Cont0205d1e0
    add r0, r5, #0x3000
    ldr r0, [r0, #0xcb0]
    bl _Z28CallFunc0204b04cOverList0x98P12Cont0205d274
    add r0, r5, #0x3000
    ldr r0, [r0, #0xcb0]
    bl _Z19InitEntries0205d2bcP11Obj0205d2bc
    add r0, r5, #0xb4
    add r0, r0, #0x3c00
    mov r1, #0x2
    bl func_ov017_021996bc
    add r0, r5, #0x3000
    ldr r0, [r0, #0xcb0]
    bl func_0205d048
    add r0, r5, #0x4000
    ldr r0, [r0, #0x74]
    mov r1, #0x0
    mov r2, #0x20
    bl memset
    add r0, r5, #0x4000
    ldr r0, [r0, #0x74]
    mov r1, #0x20
    bl _Z25CleanInvalidateCacheRangePKvj
    add r0, r5, #0x4000
    ldr r0, [r0, #0x74]
    mov r1, #0x0
    mov r2, #0x20
    bl _Z19TransferBg1CharDataiij
.L_02199940:
    mov r1, #0x4000000
    ldr r0, [r1, #0x0]
    bic r0, r0, #0x1f00
    orr r0, r0, #0x1300
    str r0, [r1, #0x0]
.L_02199954:
    mov r0, r5
    bl func_ov017_021996fc
    ldmia sp!, {r3, r4, r5, pc}
.L_02199960: .word 0x4000050
    arm_func_end func_ov017_02199780

