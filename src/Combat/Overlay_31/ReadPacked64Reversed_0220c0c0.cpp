#include <globaldefs.h>

// USA: func_ov031_0220c0c0
ARM unsigned long long ReadPacked64Reversed_0220c0c0(unsigned short* p) {
	asm {
		ldrh r2, [r0, #0]
		ldrh r3, [r0, #-2]
		orr r1, r3, r2, lsl #16
		ldrh r2, [r0, #-4]
		ldrh r3, [r0, #-6]
		orr r0, r3, r2, lsl #16
	}
}
