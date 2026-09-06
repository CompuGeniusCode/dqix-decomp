#include <globaldefs.h>
#include "System/Interrupts.h"
#include "System/Timing.h"

extern int data_ov031_0224e53c;
int RunTwoSteps_0220db28(void);

// USA: func_ov031_0220da1c
extern "C" ARM void func_ov031_0220da1c(int newState) {
	int state = DisableIRQInterrupts();
	if (*(int*)((char*)data_ov031_0224e53c + 0x2260) == 9 && newState != 9) {
		CancelAlarm((Alarm*)((char*)data_ov031_0224e53c + 0x22cc));
	}
	char* base2000b = (char*)data_ov031_0224e53c;
	base2000b += 0x2000;
	if (*(int*)(base2000b + 0x260) != 0xb) {
		*(int*)(base2000b + 0x260) = newState;
	}
	if (newState == 9) {
		SetTimeout((Alarm*)((char*)data_ov031_0224e53c + 0x22cc), 0x22f5341, (Alarm::PFNCompletion)&RunTwoSteps_0220db28, NULL);
	}
	SetIRQInterruptState(state);
}
