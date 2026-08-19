#include <globaldefs.h>

// KEEP-NAME: the ROM symbol is a curated name, not a func_ tag.
// USA: func_020c8348
//
// PROVENANCE: pmd-sky/lib/NitroSDK/src/os/os_init.c -- OSi_WaitVCount0. NitroSDK OS init:
// disable IME, spin until VCOUNT==0, restore IME.
// No C attempt: `str ip, [ip, #0x208]` reuses the HW_REG_BASE address register itself as
// the stored data value to clear IME (0x04000000 has bit0 clear) -- the documented
// address-base-register-reused-as-data-operand tell. No compiler materialises a zero this
// way; it always loads a fresh literal into its own register. Reference confirms the same
// trick byte-for-byte.
ARM asm void WaitForVCountZero(void) {
    mov r12, #0x4000000
    ldr r1, [r12, #0x208]
    str r12, [r12, #0x208]
loop:
    ldrh r0, [r12, #6]
    cmp r0, #0
    bne loop
    str r1, [r12, #0x208]
    bx lr
}
