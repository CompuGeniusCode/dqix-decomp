#include <globaldefs.h>
#include "System/Timing.h"

extern "C" unsigned long long _ll_udiv(unsigned long long dividend, unsigned int divisor, unsigned int flag);
extern "C" int func_ov031_02214fc8(void* obj, int mode);
extern "C" int func_ov031_022151b0(void*, void*, int, int);
extern "C" int FindNthSetBit_02214afc(unsigned int n);

extern int data_ov031_02245fb0;

struct LowNibble02214ea8 { unsigned char low4 : 4; unsigned char high4 : 4; };

// USA: func_ov031_02214ea8
#pragma optimize_for_size off
ARM int AdvanceSendSlotAlt_02214ea8(char* obj) {
	unsigned long long diff = GetCurrentTimestamp() - *(unsigned long long*)(obj + 0xcb0);
	unsigned long long quotient = _ll_udiv(diff << 6, 0x82ea, 0);
	if (quotient < 0x96) {
		unsigned char idx = *(unsigned char*)(obj + 0xd0f);
		if (((LowNibble02214ea8*)(obj + idx * 0x24 + 0x300))->low4 != 1)
			goto ret5;
	}

	{
		char* base = obj + 0x300;
		unsigned char idx = *(unsigned char*)(obj + 0xd0f);
		int off = idx * 0x24;
		*(unsigned char*)(base + off) &= ~0xf;

		idx = *(unsigned char*)(obj + 0xd0f);
		idx++;
		*(unsigned char*)(obj + 0xd0f) = idx;

		unsigned char maxCount = *(unsigned char*)(obj + 0xd10);
		if (idx >= maxCount) {
			unsigned char cnt = *(unsigned char*)(obj + 0xd15) + 1;
			*(unsigned char*)(obj + 0xd15) = cnt;
			*(unsigned char*)(obj + 0xd0f) = 0;
			*(unsigned char*)(obj + 0xd11) = FindNthSetBit_02214afc(*(unsigned char*)(obj + 0xd15));
		}

		if (*(signed char*)(obj + 0xd11) < 0) {
			*(unsigned char*)(obj + 0xd15) = 0;
			return func_ov031_02214fc8(obj, 5);
		}

		*(unsigned long long*)(obj + 0xcb0) = GetCurrentTimestamp();
		idx = *(unsigned char*)(obj + 0xd0f);
		char* base1 = obj + 0x304;
		int off2 = idx * 0x24;
		func_ov031_022151b0(&data_ov031_02245fb0, base1 + off2, *(signed char*)(obj + 0xd11), 0x300000);
	}
ret5:
	return 5;
}
