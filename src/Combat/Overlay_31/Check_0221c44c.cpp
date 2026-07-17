#include <globaldefs.h>

extern "C" void func_ov031_0221ae00(void*);

// USA: func_ov031_0221c44c
ARM int Check_0221c44c(void) {
	char buf[0x14];
	func_ov031_0221ae00(buf);
	asm {
		ldr r0, [sp, #0xc]
		ldr r1, [sp, #8]
		cmp r0, #0
		cmpeq r1, #0
		mov r0, #0
		bne skip_0221c44c
		ldr r1, [sp, #4]
		ldr r2, [sp, #0]
		cmp r1, r0
		cmpeq r2, r0
		addeq sp, sp, #0x14
		moveq r0, #1
		ldmeqia sp!, {pc}
	skip_0221c44c:
	}
}
