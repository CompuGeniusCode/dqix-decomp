// func_0200f31c at 0x0200f31c is hand-written library assembly, transcribed
// instruction-for-instruction from the ROM. It is not un-decompiled C.
//
// PROVENANCE: sm64ds-decomp src/func_020717c0.c -- asm there too
//
// Assembly rather than an mwccarm `asm` block because the inline assembler cannot
// express this one. Mnemonics are the canonical ARM spellings mwasmarm accepts.

	.section .text
	.arm
	.extern func_0200eca0

	.global func_0200f31c

func_0200f31c:
	mov ip, sp
	sub sp, sp, #0x70
	str r4, [sp, #0x2c]
	str r5, [sp, #0x30]
	str r6, [sp, #0x34]
	str r7, [sp, #0x38]
	str r8, [sp, #0x3c]
	str r9, [sp, #0x40]
	str r10, [sp, #0x44]
	str r11, [sp, #0x48]
	str ip, [sp, #0x14]
	str ip, [sp, #0x5c]
	str lr, [sp, #0x10]
	mov ip, #0
	str ip, [sp]
	str ip, [sp, #4]
	str ip, [sp, #8]
	mov r0, sp
	b func_0200eca0
