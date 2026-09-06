#include <globaldefs.h>
#include "System/ProcessorContext.h"

extern unsigned int data_ov031_02249680;
extern ProcessorContext data_ov031_0224cbe8;
extern ProcessorContext data_ov031_0224cb28;

// USA: func_ov031_0220057c
ARM void SetPriorityAndApplyToContexts_0220057c(unsigned int priority) {
	data_ov031_02249680 = priority;
	ChangeContextPriority(&data_ov031_0224cbe8, priority);
	ChangeContextPriority(&data_ov031_0224cb28, priority);
}
