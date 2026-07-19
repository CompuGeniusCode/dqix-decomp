#include <globaldefs.h>
#include "System/Interrupts.h"
#include "Memory/SafeAllocator.h"

extern SafeAllocator data_ov031_02291e3c;

// USA: func_ov031_02243450
ARM void* AllocFromAllocator1e3c_02243450(int unused, unsigned int size) {
	int state = DisableIRQInterrupts();
	void* p = data_ov031_02291e3c.Allocate(size);
	SetIRQInterruptState(state);
	return p;
}
