#include <globaldefs.h>
#include "System/Memory.h"

extern "C" int func_ov031_0221474c(void*);
extern int data_ov031_02245fe0;

// USA: func_ov031_02214600
ARM int Advance_02214600(void *obj) {
	asm {
		mov r5, r0
		add r4, r5, #0x300
		bl func_ov031_0221474c
		ldrb r1, [r5, #0xd0c]
		mov r5, r0
		mov r0, #0x24
		mla r4, r5, r0, r4
		mov r1, r1, lsl #0x1c
		movs r0, r1, lsr #0x1c
		cmpne r0, #6
		bne skip_02214600
		ldr r0, =data_ov031_02245fe0
		add r1, r4, #4
		mov r2, #8
		bl VectorizedInvertedMemcpy
		mov r1, #8
		strb r1, [r4, #3]
		add r0, r5, #1
		strb r1, [r4, #1]
		and r5, r0, #0xff
	skip_02214600:
		mov r0, r5
	}
}
