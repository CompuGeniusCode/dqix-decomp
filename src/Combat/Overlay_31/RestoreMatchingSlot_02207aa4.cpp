#include <globaldefs.h>
#include "System/Interrupts.h"
#include "System/Memory.h"
#include "System/Timing.h"

struct Entry02207aa4 {
	char pad[0x20];
	char copyData[0x30];
	int field50;
	int field54;
	unsigned short field58;
	unsigned char field5a;
	char pad2[0x5c - 0x5b];
};

extern Entry02207aa4 data_ov031_0224e3b8[4];

// USA: func_ov031_02207aa4  (semantic: RestoreMatchingSlot_02207aa4)
extern "C" ARM void func_ov031_02207aa4(void* obj, int a, int b) {
	int i;
	int oldIRQ;
	Entry02207aa4* entry;
	oldIRQ = DisableIRQInterrupts();
	*(unsigned char*)((char*)obj + 0x30) = 0;
	entry = data_ov031_0224e3b8;
	i = 0;
	do {
		if (entry->field5a != 0 && entry->field54 == a && entry->field58 == b) {
			VectorizedInvertedMemcpy(entry, (char*)obj + 0x74, 0x20);
			VectorizedInvertedMemcpy(entry->copyData, obj, 0x30);
			entry->field50 = (int)(GetCurrentTimestamp() >> 16);
			*(unsigned char*)((char*)obj + 0x30) = 1;
			break;
		}
		i++;
		entry++;
	} while (i < 4);
	SetIRQInterruptState(oldIRQ);
}
