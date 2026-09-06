#include <globaldefs.h>
#include "System/Interrupts.h"
#include "Memory/SafeAllocator.h"

extern SafeAllocator data_ov031_02291e3c;

// USA: func_ov031_02243484
ARM void FreeFromAllocator1e3c_02243484(int unused, void* ptr) {
	if (ptr == NULL) {
		return;
	}
	int state = DisableIRQInterrupts();
	data_ov031_02291e3c.Free(ptr);
	SetIRQInterruptState(state);
}
