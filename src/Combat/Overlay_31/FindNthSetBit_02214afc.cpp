#include <globaldefs.h>

void* GetFieldPtrByMask_022133f8(int);

// USA: func_ov031_02214afc
ARM int FindNthSetBit_02214afc(int n) {
	asm {
		mov r4, r0
		mov r0, #0x10
		bl GetFieldPtrByMask_022133f8
		add r0, r0, #0xd00
		ldrh ip, [r0, #0x16]
		cmp ip, #0
		mvneq r0, #0
		ldmeqia sp!, {r4, pc}
		mov r2, #0
		mov r3, r2
		mov r1, #1
	loop_02214afc:
		tst ip, r1, lsl r2
		beq skip_02214afc
		cmp r3, r4
		moveq r0, r2, lsl #0x18
		moveq r0, r0, asr #0x18
		ldmeqia sp!, {r4, pc}
		add r0, r3, #1
		and r3, r0, #0xff
	skip_02214afc:
		add r0, r2, #1
		and r2, r0, #0xff
		cmp r2, #0xd
		blo loop_02214afc
		mvn r0, #0
	end_02214afc:
	}
}
