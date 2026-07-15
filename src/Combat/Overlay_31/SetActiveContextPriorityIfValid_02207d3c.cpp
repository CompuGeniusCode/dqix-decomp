#include <globaldefs.h>
#include "System/ProcessorContext.h"

// USA: func_ov031_02207d3c
ARM void SetActiveContextPriorityIfValid_02207d3c(unsigned int priority) {
	if (priority < 0x20) {
		ChangeContextPriority(data_02111304.activeContext, priority);
	}
}
