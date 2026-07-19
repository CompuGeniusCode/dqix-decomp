#include <globaldefs.h>

struct DataObj0224e5ac { void *pad0; void* (*field4)(void*, int); };
extern struct DataObj0224e5ac data_ov031_0224e5ac;
struct Header02211b28 { int magic; int value; };
void* InitHeaderMagic_02211b28(Header02211b28*, int);

// USA: func_ov031_02211b64  (semantic: Alloc_02211b64)
extern "C" ARM void* func_ov031_02211b64(void *a, int b) {
	asm {
		ldr r3, =data_ov031_0224e5ac
		mov r4, b
		ldr r3, [r3, #4]
		add r1, r4, #0x20
		blx r3
		cmp r0, #0
		moveq r0, #0
		ldmeqia sp!, {r4, pc}
		mov r1, r4
		bl InitHeaderMagic_02211b28
	}
}
