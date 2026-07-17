#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void* func_ov031_02218e2c(void*, int);
extern "C" int func_ov031_0221ac6c(void*, int, char*, int);

// USA: func_ov031_02218e84
ARM int FindAndTerminate_02218e84(void *a, int b, char *c, int d) {
	asm {
		mov r6, r2
		mov r5, r3
		bl func_ov031_02218e2c
		movs r4, r0
		moveq r0, #0
		ldmeqia sp!, {r4, r5, r6, pc}
		bl strlen
		mov r1, r0
		mov r0, r4
		mov r2, r6
		mov r3, r5
		bl func_ov031_0221ac6c
		mvn r1, #0
		cmp r0, r1
		ldmeqia sp!, {r4, r5, r6, pc}
		cmp r0, r5
		ldmhsia sp!, {r4, r5, r6, pc}
		mov r1, #0
		strb r1, [r6, r0]
	}
}
