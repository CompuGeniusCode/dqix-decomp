#include <globaldefs.h>

extern "C" void func_0201fdd0();
extern "C" void* _Z15GetBattleStructv();
extern "C" void* _Z25GetCombatantWithFlag0x800P12BattleStructi(void*, int);
extern int data_020fdcb0;

// USA: func_0201fd38
ARM void SubmitFlag0x800CombatantDataB0201fd38(void* p0, void* p1, int combatantId) {
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
        add r0, r0, r4, lsl #0x5
        ldr r3, [r0, #0x4]
        cmp r3, #0x0
        blt skip
        ldr r1, [r0, #0xc]
        mov r0, #0x30
        str r1, [sp, #0x0]
        str r0, [sp, #0x4]
        mov r0, #0x1c
        str r0, [sp, #0x8]
        mov r0, #0x7
        str r0, [sp, #0xc]
        mov r0, #0x24
        str r0, [sp, #0x10]
        mov r0, #0xb
        str r0, [sp, #0x14]
        mov ip, #0xc
        mov r0, r6
        mov r1, r5
        mov r2, r4
        str ip, [sp, #0x18]
        mov r4, #0x1
        str r4, [sp, #0x1c]
        bl func_0201fdd0
skip:
        add sp, sp, #0x20
    }
}
