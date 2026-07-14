#include <globaldefs.h>
#include "System/DMA.h"
#include "System/Interrupts.h"
#include "System/GamecardBusOwnership.h"
#include "Filesystem/CardReadManager.h"

void RetrySendIpcCommand(int arg);

extern "C" void func_020c9be0(void);
extern "C" void func_01ff81e4(void);

// USA: func_020c98f0
ARM asm void ResetSystemAndBoot020c98f0(int param) {
    stmdb sp!, {r4, lr}
    ldr r1, =0x27ffc40
    mov r4, r0
    ldrh r0, [r1, #0x0]
    cmp r0, #0x2
    moveq r0, #0x1
    movne r0, #0x0
    cmp r0, #0x0
    beq skip1
    bl func_020c9be0
skip1:
    bl GenerateLockOwnerID
    mov r0, r0, lsl #0x10
    mov r0, r0, lsr #0x10
    bl NitroVM_Command_AcquireCardReadResources
    ldr r0, =0x40000
    bl SetSpecificInterruptsEnabled
    ldr r0, =0xfffbffff
    bl AcknowledgeSpecificInterrupts
    ldr r0, =0x0
    bl ResetDMAChannel
    ldr r0, =0x1
    bl ResetDMAChannel
    ldr r0, =0x2
    bl ResetDMAChannel
    ldr r0, =0x3
    bl ResetDMAChannel
    ldr r1, =0x27ffc20
    ldr r0, =0x10
    str r4, [r1, #0x0]
    bl RetrySendIpcCommand
    ldr r0, =0x27e3f80
    ldr r1, =0x400
    sub r0, r0, r1
    mov sp, r0
    bl func_01ff81e4
    ldmia sp!, {r4, pc}
}
