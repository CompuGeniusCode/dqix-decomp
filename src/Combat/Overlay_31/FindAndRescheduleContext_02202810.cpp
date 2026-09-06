#include <globaldefs.h>
#include "System/ProcessorContext.h"

extern "C" void* func_ov031_02201e0c(int a, int b);

struct ContextEntry_02202810 {
	ProcessorContext* field0;
	int field4;
	unsigned char field8;
};

// USA: func_ov031_02202810
ARM int FindAndRescheduleContext_02202810(int a, int b) {
	ContextEntry_02202810* p = (ContextEntry_02202810*)func_ov031_02201e0c(a, b);
	if (p == NULL) {
		return (int)p;
	}
	CycleCurrentPriorityContexts();
	p->field8 = 0;
	if ((unsigned int)(p->field4 - 1) > 1) {
		return p->field4 - 1;
	}
	p->field4 = 0;
	MarkContextReadyAndSwitch(p->field0);
}
