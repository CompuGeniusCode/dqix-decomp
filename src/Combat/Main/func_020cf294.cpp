#include <globaldefs.h>

// USA: func_020cf294
//
// PROVENANCE: pokeheartgold/lib/asm/nitro.s — RtcCommonCallback. NitroSDK RTC alarm/status
// completion callback, hand-written SDK assembly, instruction-for-instruction identical (only
// call targets and literal-pool addresses differ). DQIX repurposes this exact routine as the
// arm9 IPC command-5 handler for its combat "slot system": InitSlotSystem020cf020.cpp already
// forward-declares and registers this address as `func_020cf294`, so the name is kept as-is
// rather than renamed to match the SDK routine's original semantics.
extern char data_02111818;
int BcdToBinary(unsigned int packed);
extern "C" void func_020cfc00(void);
int CheckEntry5For0x27(void);

#define RTC_REG_A 0x027ffde8
#define RTC_REG_B 0x027ffdec
#define RTC_REG_C 0x027ffdea

extern "C" ARM asm void func_020cf294(unsigned int a, unsigned int b, unsigned int c) {
    stmdb sp!, {r3, r4, r5, lr}
    cmp r2, #0
    beq _L5c
    ldr r0, =data_02111818
    ldr r1, [r0, #0x24]
    cmp r1, #0
    movne r1, #0
    strne r1, [r0, #0x24]
    ldr r0, =data_02111818
    ldr r1, [r0, #0xc]
    cmp r1, #0
    movne r1, #0
    strne r1, [r0, #0xc]
    ldr r0, =data_02111818
    ldr r2, [r0, #0x10]
    cmp r2, #0
    ldmeqia sp!, {r3, r4, r5, pc}
    mov r1, #0
    str r1, [r0, #0x10]
    ldr r1, [r0, #0x1c]
    mov r0, #6
    blx r2
    ldmia sp!, {r3, r4, r5, pc}
_L5c:
    and r0, r1, #0x7f00
    mov r0, r0, lsr #8
    and r0, r0, #0xff
    cmp r0, #0x30
    and r2, r1, #0xff
    bne _L8c
    ldr r0, =data_02111818
    ldr r0, [r0, #0x28]
    cmp r0, #0
    ldmeqia sp!, {r3, r4, r5, pc}
    blx r0
    ldmia sp!, {r3, r4, r5, pc}
_L8c:
    cmp r2, #0
    bne _L4b0
    ldr r0, =data_02111818
    mov r4, #0
    ldr r1, [r0, #0x20]
    cmp r1, #0xf
    addls pc, pc, r1, lsl #2
    b _L49c
    b _Lec
    b _L148
    b _L198
    b _L4f8
    b _L4f8
    b _L4f8
    b _L240
    b _L270
    b _L294
    b _L33c
    b _L3f0
    b _L4f8
    b _L4f8
    b _L4f8
    b _L4f8
    b _L4f8
_Lec:
    ldr r1, =RTC_REG_A
    ldr r5, [r0, #0x14]
    ldr r0, [r1]
    mov r0, r0, lsl #0x18
    mov r0, r0, lsr #0x18
    bl BcdToBinary
    ldr r1, =RTC_REG_A
    str r0, [r5]
    ldr r0, [r1]
    mov r0, r0, lsl #0x13
    mov r0, r0, lsr #0x1b
    bl BcdToBinary
    ldr r1, =RTC_REG_A
    str r0, [r5, #4]
    ldr r0, [r1]
    mov r0, r0, lsl #0xa
    mov r0, r0, lsr #0x1a
    bl BcdToBinary
    str r0, [r5, #8]
    mov r0, r5
    bl func_020cfc00
    str r0, [r5, #0xc]
    b _L4f8
_L148:
    ldr r1, =RTC_REG_B
    ldr r5, [r0, #0x14]
    ldr r0, [r1]
    mov r0, r0, lsl #0x1a
    mov r0, r0, lsr #0x1a
    bl BcdToBinary
    ldr r1, =RTC_REG_B
    str r0, [r5]
    ldr r0, [r1]
    mov r0, r0, lsl #0x11
    mov r0, r0, lsr #0x19
    bl BcdToBinary
    ldr r1, =RTC_REG_B
    str r0, [r5, #4]
    ldr r0, [r1]
    mov r0, r0, lsl #9
    mov r0, r0, lsr #0x19
    bl BcdToBinary
    str r0, [r5, #8]
    b _L4f8
_L198:
    ldr r1, =RTC_REG_A
    ldr r5, [r0, #0x14]
    ldr r0, [r1]
    and r0, r0, #0xff
    bl BcdToBinary
    ldr r1, =RTC_REG_A
    str r0, [r5]
    ldr r0, [r1]
    mov r0, r0, lsl #0x13
    mov r0, r0, lsr #0x1b
    bl BcdToBinary
    ldr r1, =RTC_REG_A
    str r0, [r5, #4]
    ldr r0, [r1]
    mov r0, r0, lsl #0xa
    mov r0, r0, lsr #0x1a
    bl BcdToBinary
    str r0, [r5, #8]
    mov r0, r5
    bl func_020cfc00
    ldr r1, =RTC_REG_B
    str r0, [r5, #0xc]
    ldr r0, [r1]
    ldr r1, =data_02111818
    mov r0, r0, lsl #0x1a
    mov r0, r0, lsr #0x1a
    ldr r5, [r1, #0x18]
    bl BcdToBinary
    ldr r1, =RTC_REG_B
    str r0, [r5]
    ldr r0, [r1]
    mov r0, r0, lsl #0x11
    mov r0, r0, lsr #0x19
    bl BcdToBinary
    ldr r1, =RTC_REG_B
    str r0, [r5, #4]
    ldr r0, [r1]
    mov r0, r0, lsl #9
    mov r0, r0, lsr #0x19
    bl BcdToBinary
    str r0, [r5, #8]
    b _L4f8
_L240:
    ldr r1, =RTC_REG_C
    ldr r2, [r0, #0x14]
    ldrh r0, [r1]
    mov r0, r0, lsl #0x1c
    mov r0, r0, lsr #0x1c
    cmp r0, #4
    bne _L268
    mov r0, #1
    str r0, [r2]
    b _L4f8
_L268:
    str r4, [r2]
    b _L4f8
_L270:
    ldr r1, =RTC_REG_C
    ldr r2, [r0, #0x14]
    ldrh r0, [r1]
    mov r0, r0, lsl #0x19
    movs r0, r0, lsr #0x1f
    movne r0, #1
    strne r0, [r2]
    streq r4, [r2]
    b _L4f8
_L294:
    ldr r1, =RTC_REG_B
    ldr r5, [r0, #0x14]
    ldr r0, [r1]
    mov r0, r0, lsl #0x1d
    mov r0, r0, lsr #0x1d
    str r0, [r5]
    ldr r0, [r1]
    mov r0, r0, lsl #0x12
    mov r0, r0, lsr #0x1a
    bl BcdToBinary
    ldr r1, =RTC_REG_B
    str r0, [r5, #4]
    ldr r0, [r1]
    mov r0, r0, lsl #9
    mov r0, r0, lsr #0x19
    bl BcdToBinary
    str r0, [r5, #8]
    mov r1, r4
    ldr r0, =RTC_REG_B
    str r1, [r5, #0xc]
    ldr r0, [r0]
    mov r0, r0, lsl #0x18
    movs r0, r0, lsr #0x1f
    ldrne r0, [r5, #0xc]
    addne r0, r0, #1
    strne r0, [r5, #0xc]
    ldr r0, =RTC_REG_B
    ldr r0, [r0]
    mov r0, r0, lsl #0x10
    movs r0, r0, lsr #0x1f
    ldrne r0, [r5, #0xc]
    addne r0, r0, #2
    strne r0, [r5, #0xc]
    ldr r0, =RTC_REG_B
    ldr r0, [r0]
    mov r0, r0, lsl #8
    movs r0, r0, lsr #0x1f
    beq _L4f8
    ldr r0, [r5, #0xc]
    add r0, r0, #4
    str r0, [r5, #0xc]
    b _L4f8
_L33c:
    ldr r3, [r0, #0x24]
    cmp r3, #0
    bne _L3e8
    ldr r1, [r0, #0x14]
    ldr r2, =RTC_REG_C
    ldr r1, [r1]
    cmp r1, #1
    ldrh r1, [r2]
    bne _L3a8
    mov r1, r1, lsl #0x1c
    mov r1, r1, lsr #0x1c
    cmp r1, #4
    beq _L4f8
    add r1, r3, #1
    str r1, [r0, #0x24]
    ldrh r0, [r2]
    bic r0, r0, #0xf
    orr r0, r0, #4
    strh r0, [r2]
    bl CheckEntry5For0x27
    cmp r0, #0
    bne _L4f8
    ldr r0, =data_02111818
    mov r1, r4
    str r1, [r0, #0x24]
    mov r4, #3
    b _L4f8
_L3a8:
    mov r1, r1, lsl #0x1c
    movs r1, r1, lsr #0x1c
    beq _L4f8
    add r1, r3, #1
    str r1, [r0, #0x24]
    ldrh r0, [r2]
    bic r0, r0, #0xf
    strh r0, [r2]
    bl CheckEntry5For0x27
    cmp r0, #0
    bne _L4f8
    ldr r0, =data_02111818
    mov r1, r4
    str r1, [r0, #0x24]
    mov r4, #3
    b _L4f8
_L3e8:
    str r4, [r0, #0x24]
    b _L4f8
_L3f0:
    ldr r3, [r0, #0x24]
    cmp r3, #0
    bne _L494
    ldr r1, [r0, #0x14]
    ldr r2, =RTC_REG_C
    ldr r1, [r1]
    cmp r1, #1
    ldrh r1, [r2]
    bne _L454
    mov r1, r1, lsl #0x19
    movs r1, r1, lsr #0x1f
    bne _L4f8
    add r1, r3, #1
    str r1, [r0, #0x24]
    ldrh r0, [r2]
    orr r0, r0, #0x40
    strh r0, [r2]
    bl CheckEntry5For0x27
    cmp r0, #0
    bne _L4f8
    ldr r0, =data_02111818
    mov r1, r4
    str r1, [r0, #0x24]
    mov r4, #3
    b _L4f8
_L454:
    mov r1, r1, lsl #0x19
    movs r1, r1, lsr #0x1f
    beq _L4f8
    add r1, r3, #1
    str r1, [r0, #0x24]
    ldrh r0, [r2]
    bic r0, r0, #0x40
    strh r0, [r2]
    bl CheckEntry5For0x27
    cmp r0, #0
    bne _L4f8
    ldr r0, =data_02111818
    mov r1, r4
    str r1, [r0, #0x24]
    mov r4, #3
    b _L4f8
_L494:
    str r4, [r0, #0x24]
    b _L4f8
_L49c:
    ldr r0, =data_02111818
    mov r1, #0
    str r1, [r0, #0x24]
    mov r4, #4
    b _L4f8
_L4b0:
    ldr r0, =data_02111818
    mov r1, #0
    str r1, [r0, #0x24]
    cmp r2, #4
    addls pc, pc, r2, lsl #2
    b _L4f4
    b _L4f4
    b _L4dc
    b _L4e4
    b _L4ec
    b _L4f4
_L4dc:
    mov r4, #4
    b _L4f8
_L4e4:
    mov r4, #5
    b _L4f8
_L4ec:
    mov r4, #1
    b _L4f8
_L4f4:
    mov r4, #6
_L4f8:
    ldr r0, =data_02111818
    ldr r1, [r0, #0x24]
    cmp r1, #0
    ldmneia sp!, {r3, r4, r5, pc}
    ldr r1, [r0, #0xc]
    cmp r1, #0
    movne r1, #0
    strne r1, [r0, #0xc]
    ldr r0, =data_02111818
    ldr r2, [r0, #0x10]
    cmp r2, #0
    ldmeqia sp!, {r3, r4, r5, pc}
    mov r1, #0
    str r1, [r0, #0x10]
    ldr r1, [r0, #0x1c]
    mov r0, r4
    blx r2
    ldmia sp!, {r3, r4, r5, pc}
}
