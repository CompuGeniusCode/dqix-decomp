#include <globaldefs.h>
#include "System/Interrupts.h"
#include "System/ProcessorContext.h"

struct GlobalStruct0224c980_02200af8 {
	char pad0[0x28];
	unsigned int field28;
	char pad1[0x30 - 0x28 - 4];
	volatile unsigned int field30;
	char pad2[0x54 - 0x30 - 4];
	unsigned int field54;
	char pad3[0x58 - 0x54 - 4];
	unsigned char* field58;
	char pad4[0x5c - 0x58 - 4];
	unsigned int field5c;
};

extern GlobalStruct0224c980_02200af8 data_ov031_0224c980;

// USA: func_ov031_02200af8  (semantic: DequeueOrBlockUntilAvailable_02200af8)  (semantic: DequeueOrBlockUntilAvailable_02200af8)
extern "C" ARM void* func_ov031_02200af8(unsigned int* outLen) {
	int oldIRQ = DisableIRQInterrupts();
	if (data_ov031_0224c980.field30 == data_ov031_0224c980.field28) {
		do {
			data_ov031_0224c980.field54 = (unsigned int)data_02111304.activeContext;
			BlockCurrentContext(NULL);
			data_ov031_0224c980.field54 = 0;
		} while (data_ov031_0224c980.field30 == data_ov031_0224c980.field28);
	}
	SetIRQInterruptState(oldIRQ);

	unsigned char* base = data_ov031_0224c980.field58;
	unsigned int value;
	do {
		if (data_ov031_0224c980.field5c - data_ov031_0224c980.field30 < 2) {
			data_ov031_0224c980.field30 = 0;
		}
		value = *(unsigned short*)(base + data_ov031_0224c980.field30);
		if (value == 0) {
			data_ov031_0224c980.field30 = 0;
		}
	} while (value == 0);

	*outLen = value - 2;
	return data_ov031_0224c980.field58 + data_ov031_0224c980.field30 + 2;
}
