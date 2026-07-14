#include <globaldefs.h>

extern "C" void func_0201fdd0(void* a0, void* a1, int combatantId, int b0, int b1, int b2, int b3, int b4, int b5, int b6, int b7);
extern "C" void* _Z15GetBattleStructv();
extern "C" void* _Z25GetCombatantWithFlag0x800P12BattleStructi(void*, int);
extern int data_020fdcb0;

// USA: func_0201fca0
ARM void SubmitFlag0x800CombatantDataA0201fca0(void* p0, void* p1, int combatantId) {
    asm {
        sub sp, sp, #0x20
        mov r4, r2
        mov r6, r0
        mov r5, r1
        bl _Z15GetBattleStructv
        mov r1, r4
        bl _Z25GetCombatantWithFlag0x800P12BattleStructi
        cmp r0, #0x0
        beq skip
        ldr r0, =data_020fdcb0
        ldr r3, [r0, r4, lsl #0x5]
        add r0, r0, r4, lsl #0x5
        cmp r3, #0x0
        blt skip
        ldr r1, [r0, #0x8]
        mov r0, #0x30
        str r1, [sp, #0x0]
        str r0, [sp, #0x4]
        mov r0, #0x10
        str r0, [sp, #0x8]
        mov r0, #0x7
        str r0, [sp, #0xc]
        mov r0, #0x18
        str r0, [sp, #0x10]
        mov r0, #0x9
        str r0, [sp, #0x14]
        mov ip, #0xa
        mov r0, r6
        mov r1, r5
        mov r2, r4
        str ip, [sp, #0x18]
        mov r4, #0x0
        str r4, [sp, #0x1c]
        bl func_0201fdd0
skip:
        add sp, sp, #0x20
    }
}
