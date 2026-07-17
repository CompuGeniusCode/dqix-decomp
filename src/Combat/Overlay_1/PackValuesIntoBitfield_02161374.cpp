#include <globaldefs.h>

extern "C" void* func_ov017_0218b5b0(void);
extern "C" int func_ov017_021d60f4(void*);

// USA: func_ov001_02161374
ARM int PackValuesIntoBitfield_02161374(void* self, int count) {
	char* base = (char*)func_ov017_0218b5b0() + 0x3000;
	int* e = *(int**)(base + 0x734);
	int i;
	for (i = 0; i < count; i++) {
		int v = func_ov017_021d60f4(self);
		asm {
			ldr r2, [e, #0xf8]
		}
		self = (char*)self + 0x8;
		asm {
			mov r1, r2, lsl #0x5
			orr v, v, r1, lsr #0x5
			and r1, r2, #0xf8000000
			bic v, v, #0xf8000000
			orr v, r1, v
			str v, [e, #0xf8]
		}
	}
	return 1;
}
