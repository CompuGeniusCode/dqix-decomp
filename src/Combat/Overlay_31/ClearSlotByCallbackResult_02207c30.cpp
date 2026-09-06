#include <globaldefs.h>
#include "System/Interrupts.h"

struct Entry02207c30 {
	char pad[0x5a];
	unsigned char field5a;
	char pad2[0x5c - 0x5b];
};

extern Entry02207c30 data_ov031_0224e3b8[4];

extern "C" int func_02001aec(void* entry, void* arg1, int arg2);

// USA: func_ov031_02207c30
ARM void ClearSlotByCallbackResult_02207c30(void* obj) {
	int i;
	int oldIRQ;
	Entry02207c30* entry;
	oldIRQ = DisableIRQInterrupts();
	entry = data_ov031_0224e3b8;
	i = 0;
	do {
		if (entry->field5a != 0) {
			if (func_02001aec(entry, (char*)obj + 0x74, 0x20) == 0) {
				entry->field5a = 0;
				break;
			}
		}
		i++;
		entry++;
	} while (i < 4);
	SetIRQInterruptState(oldIRQ);
}
