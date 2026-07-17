#include <globaldefs.h>

extern "C" void func_020ca408(void*, void*, int);

// USA: func_ov031_02213a68
ARM void Configure_02213a68(int r0v, void *r1p, int r2v, unsigned char *r3p) {
	asm {
		add ip, r3, #0x6c
		strb r0, [ip, #0x401]
		ldrh r0, [r1, #2]
		and r2, r2, #0x7f
		tst r0, #2
		mov r0, r0, asr #2
		addeq r0, r0, #0x19
		and r0, r0, #0xff
		strb r0, [ip, #0x402]
		ldrb lr, [ip, #0x403]
		mov r0, r1
		bic r1, lr, #0x7f
		orr lr, r1, r2
		add r1, r3, #0xbf0
		mov r2, #0xc0
		strb lr, [ip, #0x403]
		bl func_020ca408
	}
}
