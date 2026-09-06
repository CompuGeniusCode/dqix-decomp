#include <globaldefs.h>
#include "System/Timing.h"

extern "C" unsigned long long _ll_udiv(unsigned long long dividend, unsigned int divisor, unsigned int flag);
extern "C" int func_ov031_02214fc8(void* obj, int mode);
extern "C" int func_ov031_022151b0(void*, void*, int, int);

struct SlotFlags02214d80 { unsigned char pad : 7; unsigned char active : 1; };

// USA: func_ov031_02214d80
#pragma optimize_for_size off
ARM int AdvanceSendSlot_02214d80(char* obj) {
	unsigned long long diff = GetCurrentTimestamp() - *(unsigned long long*)(obj + 0xcb0);
	unsigned long long quotient = _ll_udiv(diff << 6, 0x82ea, 0);
	if (quotient < 0x96) {
		unsigned char idx = *(unsigned char*)(obj + 0xd0f);
		if (((SlotFlags02214d80*)(obj + 0x447 + idx * 4))->active != 1)
			goto ret4;
	}

	{
		char* base = obj + 0x47;
		unsigned char idx = *(unsigned char*)(obj + 0xd0f);
		*(unsigned char*)(base + 0x400 + idx * 4) |= 0x80;

		unsigned char maxCount = *(unsigned char*)(obj + 0xd12);
		idx = *(unsigned char*)(obj + 0xd0f);
		if (idx < maxCount) {
			do {
				if (!((SlotFlags02214d80*)(obj + 0x447 + idx * 4))->active) break;
				unsigned char tmp = *(unsigned char*)(obj + 0xd0f);
				tmp = tmp + 1;
				*(unsigned char*)(obj + 0xd0f) = tmp;
				maxCount = *(unsigned char*)(obj + 0xd12);
				idx = tmp;
			} while (idx < maxCount);
		}

		if (maxCount <= idx) {
			*(unsigned char*)(obj + 0xd0f) = 0;
			return func_ov031_02214fc8(obj, 4);
		}

		*(unsigned long long*)(obj + 0xcb0) = GetCurrentTimestamp();
		idx = *(unsigned char*)(obj + 0xd0f);
		char* base1 = obj + 0x74;
		int off = idx * 0xc0;
		int val = *(unsigned short*)(obj + off + 0x4a6);
		char* base2 = obj + 0x7c;
		func_ov031_022151b0(base1 + 0x400 + off, base2 + 0x400 + off, val - 1, 0x300000);
	}
ret4:
	return 4;
}
