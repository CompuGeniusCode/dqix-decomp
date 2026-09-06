func_ov017_021b5070: ; 0x021b5070
    stmdb sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
    sub sp, sp, #0x28
    mov r9, r0
    bl _Z15GetBattleStructv
    bl _Z21GetData02104304Field4v
    ldr r1, [r9, #0xc]
    mov r5, r0
    bl func_0202fdd0
    cmp r0, #0x0
    beq .L_021b5238
    ldr r1, [r9, #0xc]
    mov r0, r5
    bl _Z20LookupListValueByKeyP12List0202fe68i
    cmp r0, #0x2
    bne .L_021b50f0
    ldr r1, [r9, #0xc]
    add r2, sp, #0x8
    add r3, sp, #0xc
    mov r0, r5
    bl _Z26GetListEntryValues0202fec8P12List0202fec8iPiS1_
    ldr r0, [sp, #0x8]
    cmp r0, #0x0
    beq .L_021b50f0
    ldr r4, [r9, #0x8]
    add r0, r4, #0x60
    str r0, [sp, #0x0]
    ldr r0, [r9, #0x8]
    ldr r1, [sp, #0x8]
    ldr r2, [sp, #0xc]
    ldr r3, [r0, #0x10]
    add r0, r4, #0x124
    bl _Z33SetupAndRunBufferedScript0209af58PvP12StreamHeaderiii
.L_021b50f0:
    ldr r1, [r9, #0xc]
    mov r0, r5
    bl func_020301c8
    mvn r0, #0x0
    str r0, [r9, #0xc]
    ldr r4, [r9, #0x8]
    add r0, sp, #0x10
    mov r1, #0x18
    bl func_0200f374
    add r1, sp, #0x10
    add r0, r4, #0x44
    bl _Z24CopyHalfwordArrayByCountP13HalfwordArrayS0_
    ldr r1, [r9, #0x8]
    mov r0, r0, lsl #0x10
    ldr r6, [r1, #0x14]
    mov r10, r0, asr #0x10
    cmp r6, #0x0
    moveq r6, #0x0
    beq .L_021b5214
    mov r0, r10, lsl #0x10
    movs r0, r0, lsr #0x10
    moveq r6, #0x0
    beq .L_021b5214
    bl _Z24ShiftInBitOnGlobalObjectv
    bl _Z30CallFunc02030110OnGlobalObjectv
    ldr r0, .L_021b5240
    ldr r1, .L_021b5244
    add r2, sp, #0x4
    bl _Z18LoadFileIntoMemoryPKcPvPj
    mov r4, r0
    bl _Z24HalveGlobalObjectCounterv
    cmp r4, #0x0
    moveq r6, #0x0
    beq .L_021b5214
    ldr r0, [sp, #0x4]
    cmp r0, #0x0
    moveq r6, #0x0
    beq .L_021b5214
    ldrsh r8, [r4, #0x0]
    mov r0, r6
    mov r1, #0xc
    mov r2, r8, lsl #0x1
    add r2, r2, #0x2
    add r7, r4, r2
    bl _ZN13SafeAllocator8AllocateEj
    mov r1, #0x0
    mov r2, #0xc
    mov r6, r0
    bl memset
    mov ip, #0x0
    mov r0, r10, lsl #0x10
    add r2, sp, #0x10
    mov r11, ip
    b .L_021b520c
.L_021b51c8:
    mov r1, ip, lsl #0x1
    mov r3, r11
    add lr, r4, #0x2
    ldrsh r10, [r2, r1]
    b .L_021b51ec
.L_021b51dc:
    ldrsh r1, [lr], #0x2
    cmp r1, r10
    beq .L_021b51f4
    add r3, r3, #0x1
.L_021b51ec:
    cmp r3, r8
    blt .L_021b51dc
.L_021b51f4:
    cmp r3, #0x0
    blt .L_021b5208
    cmp r3, r8
    ldrltb r1, [r7, r3]
    strltb r1, [r6, ip]
.L_021b5208:
    add ip, ip, #0x1
.L_021b520c:
    cmp ip, r0, lsr #0x10
    blt .L_021b51c8
.L_021b5214:
    ldr r1, .L_021b5248
    ldr r2, .L_021b524c
    mov r0, r5
    mov r3, #0x0
    str r6, [r9, #0x14]
    bl _Z21CallFunc0202fa38Mode2iiii
    str r0, [r9, #0xc]
    mov r0, #0x6
    strb r0, [r9, #0x10]
.L_021b5238:
    add sp, sp, #0x28
    ldmia sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
.L_021b5240: .word data_ov017_021d7b85
.L_021b5244: .word data_0211e33c
.L_021b5248: .word data_ov017_021d7b9b
.L_021b524c: .word data_ov017_021d7bb1
    arm_func_end func_ov017_021b5070

    .global func_ov017_021b5250
    arm_func_start func_ov017_021b5250
