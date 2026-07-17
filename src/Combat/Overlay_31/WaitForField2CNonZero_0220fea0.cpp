#include <globaldefs.h>
#include "System/ProcessorContext.h"

extern void* data_ov031_0224e580;

// USA: func_ov031_0220fea0
ARM void WaitForField2CNonZero_0220fea0(void) {
	while (data_ov031_0224e580 != NULL && *(int*)((char*)data_ov031_0224e580 + 0x2c) == 0) {
		SleepCurrentContext(100);
	}
}
