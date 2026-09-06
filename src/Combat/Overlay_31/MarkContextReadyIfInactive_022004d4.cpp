#include <globaldefs.h>
#include "System/Interrupts.h"
#include "System/ProcessorContext.h"

bool IsContextInactive(ProcessorContext* context);

struct GlobalStruct0224c980_022004d4 {
	char pad[0x44];
	int field44;
};

extern ProcessorContext data_ov031_0224cb28;
extern GlobalStruct0224c980_022004d4 data_ov031_0224c980;

// USA: func_ov031_022004d4
ARM int MarkContextReadyIfInactive_022004d4(void) {
	int oldIRQ = DisableIRQInterrupts();
	int inactive = IsContextInactive(&data_ov031_0224cb28);
	if (inactive == 0) {
		if (data_ov031_0224c980.field44 == 0) {
			data_ov031_0224c980.field44 = 1;
			MarkContextReadyAndSwitch(&data_ov031_0224cb28);
		}
	}
	SetIRQInterruptState(oldIRQ);
	return inactive;
}
