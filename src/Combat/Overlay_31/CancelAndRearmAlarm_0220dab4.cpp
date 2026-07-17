#include <globaldefs.h>
#include "System/Interrupts.h"
#include "System/Timing.h"

int RunTwoSteps_0220db28(void);

extern void* data_ov031_0224e53c;

// USA: func_ov031_0220dab4
ARM unsigned int CancelAndRearmAlarm_0220dab4(void) {
	unsigned int saved = DisableIRQInterrupts();
	CancelAlarm((Alarm*)((char*)data_ov031_0224e53c + 0x22cc));
	if (*(int*)((char*)data_ov031_0224e53c + 0x2260) == 9) {
		SetTimeout((Alarm*)((char*)data_ov031_0224e53c + 0x22cc), 0x22f5341, (Alarm::PFNCompletion)&RunTwoSteps_0220db28, 0);
	}
	return SetIRQInterruptState(saved);
}
