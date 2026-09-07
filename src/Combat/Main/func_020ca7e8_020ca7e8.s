// func_020ca7e8 at 0x020ca7e8 is hand-written library assembly, transcribed
// instruction-for-instruction from the ROM. It is not un-decompiled C.
//
// PROVENANCE: pmd-sky lib/NitroSDK/src/mi/mi_uncompress.c MI_UncompressLZ8 -- asm there too
//
// Assembly rather than an mwccarm `asm` block because the inline assembler cannot
// express this one. Mnemonics are the canonical ARM spellings mwasmarm accepts.

	.section .text
	.arm

	.global func_020ca7e8

func_020ca7e8:
	stmdb sp!, {r4, r5, r6, r7, lr}
	ldr r5, [r0], #4
	mov r2, r5, lsr #8
	mov r7, #0
	tst r5, #0xf
	bne _L1c
	b _L20
_L1c:
	mov r7, #1
_L20:
	cmp r2, #0
	ble _Lf8
	ldrb lr, [r0], #1
	mov r4, #8
_L30:
	subs r4, r4, #1
	blt _L20
	tst lr, #0x80
	bne _L54
	ldrb r6, [r0], #1
	swpb r6, r6, [r1]
	add r1, r1, #1
	sub r2, r2, #1
	b _Le0
_L54:
	ldrb r5, [r0]
	cmp r7, #0
	beq _L64
	b _L68
_L64:
	mov r6, #3
_L68:
	beq _Lac
	tst r5, #0xe0
	bne _L78
	b _L7c
_L78:
	mov r6, #1
_L7c:
	bne _Lac
	add r0, r0, #1
	and r6, r5, #0xf
	mov r6, r6, lsl #4
	tst r5, #0x10
	beq _La4
	mov r6, r6, lsl #8
	ldrb r5, [r0], #1
	add r6, r6, r5, lsl #4
	add r6, r6, #0x100
_La4:
	add r6, r6, #0x11
	ldrb r5, [r0]
_Lac:
	add r3, r6, r5, asr #4
	add r0, r0, #1
	and r5, r5, #0xf
	mov ip, r5, lsl #8
	ldrb r6, [r0], #1
	orr r5, r6, ip
	add ip, r5, #1
	sub r2, r2, r3
_Lcc:
	ldrb r5, [r1, -ip]
	swpb r5, r5, [r1]
	add r1, r1, #1
	subs r3, r3, #1
	bgt _Lcc
_Le0:
	cmp r2, #0
	bgt _Lec
	b _Lf0
_Lec:
	mov lr, lr, lsl #1
_Lf0:
	bgt _L30
	b _L20
_Lf8:
	ldmia sp!, {r4, r5, r6, r7, lr}
	bx lr
