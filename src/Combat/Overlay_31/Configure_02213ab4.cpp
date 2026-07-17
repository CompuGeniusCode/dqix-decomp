#include <globaldefs.h>

extern "C" void func_020ca408(void*, void*, int);

// USA: func_ov031_02213ab4
ARM void Configure_02213ab4(int idx, void *r1p, int r2v, unsigned char *r3p) {
	asm {
		ldrh r4, [r1, #0x2]
		add ip, r3, #0x44
		mov lr, #0xc0
		add r5, ip, #0x400
		mul ip, r0, lr
		tst r4, #0x2
		add r0, r5, r0, lsl #0x2
		mov r4, r4, asr #0x2
		addeq r4, r4, #0x19
		and r4, r4, #0xff
		ldrb lr, [r0, #0x2]
		and r4, r4, #0xff
		add r3, r3, #0x470
		cmp r4, lr
		bls skip_02213ab4
		strb r4, [r0, #0x2]
		ldrb lr, [r0, #0x3]
		and r2, r2, #0x7f
		bic lr, lr, #0x7f
		orr r2, lr, r2
		strb r2, [r0, #0x3]
	skip_02213ab4:
		mov r0, r1
		add r1, r3, ip
		mov r2, #0xc0
		bl func_020ca408
	}
}
