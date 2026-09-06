#include <globaldefs.h>

extern void* data_ov031_02290d20;

// USA: func_ov031_0223b228  (semantic: SyncSlotsAndCounters_0223b228)
extern "C" ARM void func_ov031_0223b228(void) {
	int i = 0;
	do {
		void* slot = *(void**)((char*)data_ov031_02290d20 + 0x208 + i * 4);
		if (slot == 0) {
			continue;
		}
		char* elem = (char*)data_ov031_02290d20 + 0x100 + i * 0x44;
		if (i != 1) {
			continue;
		}
		if (*(unsigned char*)((char*)data_ov031_02290d20 + 0xa93) == 1) {
			if (*(unsigned short*)elem != 0x10) {
				return;
			}
			*(unsigned int*)((char*)data_ov031_02290d20 + 0xa94) += 1;
			if ((*(unsigned int*)((char*)data_ov031_02290d20 + 0xa94) & 1) != 0) {
				continue;
			}
			*(unsigned short*)((char*)data_ov031_02290d20 + 0x200) += 1;
			if (*(unsigned short*)((char*)data_ov031_02290d20 + 0x200) >= 0x24) {
				*(unsigned short*)((char*)data_ov031_02290d20 + 0x200) = 0;
			}
		} else {
			*(unsigned short*)((char*)data_ov031_02290d20 + 0x202) = 0xbc;
			if (*(unsigned short*)elem != 0xbd) {
				continue;
			}
			*(unsigned char*)((char*)data_ov031_02290d20 + 0xa93) = 1;
			*(unsigned short*)((char*)data_ov031_02290d20 + 0x200) = 0;
			*(unsigned int*)((char*)data_ov031_02290d20 + 0xa94) = 0;
		}
	} while (++i < 16);
}
