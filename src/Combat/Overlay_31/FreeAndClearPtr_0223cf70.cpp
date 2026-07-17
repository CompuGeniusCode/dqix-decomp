#include <globaldefs.h>
#include "Memory/HPXEAllocator.h"
#include "System/Interrupts.h"

extern HPXEAllocator* data_ov031_02290d3c;

// USA: func_ov031_0223cf70
ARM void FreeAndClearPtr_0223cf70(void** p) {
	unsigned int irq = DisableSpecificInterrupts(1);
	void* v = *p;
	if (v == 0) {
		return;
	}
	data_ov031_02290d3c->Free(v);
	EnableSpecificInterrupts(irq);
	*p = 0;
}
