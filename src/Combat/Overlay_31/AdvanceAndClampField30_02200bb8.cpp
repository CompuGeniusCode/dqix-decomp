#include <globaldefs.h>
#include "System/Interrupts.h"

struct GlobalStruct0224c980_02200bb8 {
	char pad[0x30];
	volatile unsigned int field30;
	char pad2[0x58 - 0x30 - 4];
	unsigned char* field58;
	char pad3[0x5c - 0x58 - 4];
	unsigned int field5c;
};

extern GlobalStruct0224c980_02200bb8 data_ov031_0224c980;

// USA: func_ov031_02200bb8
ARM void AdvanceAndClampField30_02200bb8(void) {
	int oldIRQ = DisableIRQInterrupts();
	data_ov031_0224c980.field30 = data_ov031_0224c980.field30 +
		*(unsigned short*)(data_ov031_0224c980.field58 + data_ov031_0224c980.field30);
	if (data_ov031_0224c980.field30 >= data_ov031_0224c980.field5c) {
		data_ov031_0224c980.field30 = 0;
	}
	SetIRQInterruptState(oldIRQ);
}
