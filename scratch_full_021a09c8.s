func_ov017_021a09c8: ; 0x021a09c8
    stmdb sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
    mov r10, r0
    mov r9, #0x0
    add r7, r10, #0x38
    ldr r11, .L_021a0b84
    ldr r6, .L_021a0b88
    ldr r5, .L_021a0b8c
    mov r4, #0x14
    b .L_021a0a10
.L_021a09ec:
    mov r0, r11
    mov r1, r8
    bl _Z16AllocateAligned4P14AllocatorUnionj
    ldr r2, [r6, r9, lsl #0x3]
    mov r1, r0
    mla r0, r2, r4, r7
    mov r2, r8
    bl _ZN13SafeAllocator11CreateTypeAEPvj
    add r9, r9, #0x1
.L_021a0a10:
    ldr r8, [r5, r9, lsl #0x3]
    cmp r8, #0x0
    bne .L_021a09ec
    add r0, r10, #0x278
    add r0, r0, #0x2800
    bl _Z26RestorePairTableFromBufferPi
    add r0, r10, #0xad0
    add r0, r0, #0x2000
    bl _Z23WriteGlobalPair020bb92cPi
    mov r1, #0x0
    mov r2, r1
    mov r0, #0x20000
    bl func_020bb588
    mov r9, #0x0
    add r8, r10, #0x2cc
    ldr r7, .L_021a0b90
    ldr r6, .L_021a0b94
    ldr r5, .L_021a0b98
    mov r11, #0xc
    mov r4, #0x70
    b .L_021a0a7c
.L_021a0a64:
    mul r0, r9, r11
    ldr r3, [r7, r0]
    ldr r2, [r6, r0]
    mla r0, r3, r4, r8
    bl func_0207de48
    add r9, r9, #0x1
.L_021a0a7c:
    mov r0, #0xc
    mul r0, r9, r0
    ldr r1, [r5, r0]
    cmp r1, #0x0
    bne .L_021a0a64
    add r0, r10, #0x2a8
    add r0, r0, #0x2800
    bl _Z26RestorePairTableFromBufferPi
    mov r9, #0x0
    add r8, r10, #0x2cc
    ldr r7, .L_021a0b9c
    ldr r6, .L_021a0ba0
    ldr r5, .L_021a0ba4
    mov r11, #0xc
    mov r4, #0x70
    b .L_021a0ad4
.L_021a0abc:
    mul r0, r9, r11
    ldr r3, [r7, r0]
    ldr r2, [r6, r0]
    mla r0, r3, r4, r8
    bl func_0207de48
    add r9, r9, #0x1
.L_021a0ad4:
    mov r0, #0xc
    mul r0, r9, r0
    ldr r1, [r5, r0]
    cmp r1, #0x0
    bne .L_021a0abc
    add r0, r10, #0x3fc
    add r1, r10, #0x30c
    add r6, r0, #0x800
    add r5, r1, #0xc00
    mov r4, #0x2
.L_021a0afc:
    ldmia r6!, {r0, r1, r2, r3}
    stmia r5!, {r0, r1, r2, r3}
    subs r4, r4, #0x1
    bne .L_021a0afc
    ldmia r6, {r0, r1}
    add r2, r10, #0x24
    add r3, r10, #0x334
    stmia r5, {r0, r1}
    add r6, r2, #0xc00
    add r5, r3, #0xc00
    mov r4, #0x2
.L_021a0b28:
    ldmia r6!, {r0, r1, r2, r3}
    stmia r5!, {r0, r1, r2, r3}
    subs r4, r4, #0x1
    bne .L_021a0b28
    ldmia r6, {r0, r1}
    stmia r5, {r0, r1}
    ldr r0, [r10, #0xc4c]
    str r0, [r10, #0xf5c]
    ldr r0, [r10, #0xc50]
    str r0, [r10, #0xf60]
    ldr r1, [r10, #0xc54]
    ldr r0, [r10, #0xc58]
    str r1, [r10, #0xf64]
    str r0, [r10, #0xf68]
    ldr r1, [r10, #0xc5c]
    ldr r0, [r10, #0xc60]
    str r1, [r10, #0xf6c]
    str r0, [r10, #0xf70]
    ldr r0, [r10, #0xc64]
    str r0, [r10, #0xf74]
    ldr r0, [r10, #0xc68]
    str r0, [r10, #0xf78]
    ldmia sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
.L_021a0b84: .word data_02114e20
.L_021a0b88: .word data_ov017_021d689c
.L_021a0b8c: .word data_ov017_021d68a0
.L_021a0b90: .word data_ov017_021d6758
.L_021a0b94: .word data_ov017_021d6760
.L_021a0b98: .word data_ov017_021d675c
.L_021a0b9c: .word data_ov017_021d6850
.L_021a0ba0: .word data_ov017_021d6858
.L_021a0ba4: .word data_ov017_021d6854
    arm_func_end func_ov017_021a09c8

    .global func_ov017_021a0ba8
    arm_func_start func_ov017_021a0ba8
