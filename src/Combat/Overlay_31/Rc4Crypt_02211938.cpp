#include <globaldefs.h>

// USA: func_ov031_02211938
extern "C" ARM asm void Rc4Crypt_02211938(unsigned char *ctx, const unsigned char *in, int len, unsigned char *out) {
	stmdb sp!, {r4, r5, r6, r7, r8, r9, lr}
	ldrb r7, [r0, #0]
	ldrb r6, [r0, #1]
	add r0, r0, #4
	mov lr, #0x1000000
	add r7, lr, r7, lsl #0x18
	mov r6, r6, lsl #0x18
	ldrb r9, [r0, r7, lsr #0x18]
	subs r2, r2, #1
	bmi done_02211938
loop_02211938:
	add r6, r6, r9, lsl #0x18
	subs r2, r2, #1
	ldrb r8, [r0, r6, lsr #0x18]
	ldrb r5, [r1], #1
	strb r8, [r0, r7, lsr #0x18]
	strb r9, [r0, r6, lsr #0x18]
	add r4, r9, r8
	and r4, r4, #0xff
	add r7, r7, lr
	ldrb r4, [r0, r4]
	ldrb r9, [r0, r7, lsr #0x18]
	eor r5, r5, r4
	strb r5, [r3], #1
	bge loop_02211938
done_02211938:
	sub r7, r7, lr
	mov r7, r7, lsr #0x18
	mov r6, r6, lsr #0x18
	strb r7, [r0, #-4]
	strb r6, [r0, #-3]
	ldmia sp!, {r4, r5, r6, r7, r8, r9, pc}
}
