#include <globaldefs.h>
#include "System/Memory.h"

int IsHighNibbleE_02200790(unsigned int v);
extern "C" int func_ov031_02200730(int a);
extern "C" int func_ov031_02200bfc(int a);
int LoopSleepAndCheck_02200dc8(int a);
void CopyHeaderAndDispatch_02200850(void* a, unsigned int b, void* c, unsigned int d);

extern unsigned char data_ov031_0224ce68[6];

// USA: func_ov031_02200f74  (semantic: BuildAndSendPacket_02200f74)
extern "C" ARM void func_ov031_02200f74(unsigned char* buf, unsigned int totalLen, int arg2, int arg3, unsigned int arg4, unsigned short arg5) {
	unsigned short swapped = (unsigned short)((arg5 >> 8) | (arg5 << 8));
	*(unsigned short*)(buf - 2) = swapped;

	if (IsHighNibbleE_02200790(arg4) == 0) {
		int v = func_ov031_02200730((int)arg4);
		if (v == 0) return;
		int r = func_ov031_02200bfc(v);
		if (r == 0) {
			r = LoopSleepAndCheck_02200dc8(v);
		}
		if (r == 0) return;
		VectorizedInvertedMemcpy((const void*)r, buf - 0xe, 6);
	} else {
		buf[-0xe] = 1;
		buf[-0xd] = 0;
		buf[-0xc] = 0x5e;
		buf[-0xb] = (arg4 >> 16) & 0x7f;
		buf[-0xa] = (unsigned char)(arg4 >> 8);
		buf[-9] = (unsigned char)arg4;
	}

	VectorizedInvertedMemcpy(data_ov031_0224ce68, buf - 8, 6);
	CopyHeaderAndDispatch_02200850(buf - 0xe, totalLen + 0xe, (void*)arg2, arg3);
}
