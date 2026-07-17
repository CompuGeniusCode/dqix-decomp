#include <globaldefs.h>
#include "System/Interrupts.h"

extern "C" void SleepCurrentContext(unsigned int ms);
extern int data_ov031_0224c9d0;
extern int data_ov031_0224e1c8;
extern int data_ov031_0224e1c4;

// USA: func_ov031_02206f3c
ARM int SyncOrSleep_02206f3c(void) {
	int v = data_ov031_0224c9d0;
	if (v == 0) {
		if ((data_ov031_0224e1c8 & 3) == 1) {
			if (GetProcessorMode() != 0x12) {
				SleepCurrentContext(10);
			}
		}
	} else {
		if (data_ov031_0224e1c4 == 0) {
			data_ov031_0224e1c4 = v;
		}
	}
	return data_ov031_0224c9d0;
}
