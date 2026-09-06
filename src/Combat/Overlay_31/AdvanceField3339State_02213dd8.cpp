#include <globaldefs.h>
#include "System/Timing.h"

int GetField260_0220d540(void);
struct EntityStruct022140b0;
unsigned int GetField3339Bits01_022140b0(EntityStruct022140b0*);
struct EntityStruct022140cc;
unsigned int GetField3339Bits23_022140cc(EntityStruct022140cc*);
extern "C" void func_ov031_0220d010(void*, void*, unsigned int);

// USA: func_ov031_02213dd8  (semantic: AdvanceField3339State_02213dd8)
#pragma optimize_for_size off
extern "C" ARM int func_ov031_02213dd8(char* e) {
	int state = GetField260_0220d540();
	char* slot = e + 0x470 + (*(unsigned char*)(e + 0xd13)) * 0xc0;
	if (state == 3) {
		unsigned int bits01 = GetField3339Bits01_022140b0((EntityStruct022140b0*)e);
		int inc = *(unsigned char*)(e + 0xd15) + 1;
		*(unsigned char*)(e + 0xd15) = inc;
		if (((unsigned)inc & 0xff) > 3) {
			*(unsigned char*)(e + 0xd15) = 0;
			*(char*)(e + (*(unsigned char*)(e + 0xd13)) * 4 + 0x444) = 1;
			return 9;
		}
		if (((unsigned)inc & 0xff) != 1) {
			unsigned char sub = *(unsigned char*)(e + 0xd14);
			if (sub == 1) {
				*(unsigned char*)(e + 0xd0b) &= ~0xc;
			} else if (sub == 2) {
				*(unsigned char*)(e + 0xd15) = 0;
				*(char*)(e + (*(unsigned char*)(e + 0xd13)) * 4 + 0x444) = 3;
				return 9;
			} else if (sub == 3) {
				*(unsigned char*)(e + 0xd15) = 0;
				*(char*)(e + (*(unsigned char*)(e + 0xd13)) * 4 + 0x444) = 4;
				return 9;
			} else if (((unsigned)inc & 0xff) == 3) {
				*(unsigned char*)(e + 0xd0b) &= ~0xc;
			}
		}
		unsigned int bits23 = GetField3339Bits23_022140cc((EntityStruct022140cc*)e);
		func_ov031_0220d010(slot, e + 0xcb8, bits01 | bits23);
	} else if (state == 9) {
		*(unsigned char*)(e + 0xd15) = 0;
		*(unsigned long long*)(e + 0xcb0) = GetCurrentTimestamp();
		return 0xa;
	}
	return 8;
}
