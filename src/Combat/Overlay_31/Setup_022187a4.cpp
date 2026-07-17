#include <globaldefs.h>

extern int data_ov031_02249eec;

// USA: func_ov031_022187a4
ARM int Setup_022187a4(char *obj, void *out, int len) {
	asm {
		movs r4, r2
		add r0, r0, #0x1000
		ldr r2, [r0, #0x10]
		mov r5, r1
		moveq r0, #0
		ldmeqia sp!, {r3, r4, r5, pc}
		ldr r0, =data_ov031_02249eec
		mov r1, r4
		blx r2
		str r0, [r5]
		cmp r0, #0
		moveq r0, #0
		ldmeqia sp!, {r3, r4, r5, pc}
		str r0, [r5, #4]
		str r4, [r5, #0xc]
		ldr r0, [r5]
		add r0, r0, r4
		str r0, [r5, #8]
		mov r0, #1
	}
}
