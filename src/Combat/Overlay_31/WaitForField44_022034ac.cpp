#include <globaldefs.h>
#include "System/ProcessorContext.h"
#include "System/Interrupts.h"

// USA: func_ov031_022034ac
ARM int WaitForField44_022034ac(unsigned int* out, void* obj) {
	unsigned int v;
	int priorState;
	priorState = DisableIRQInterrupts();
	v = *(unsigned int*)((char*)obj + 0x44);
	if (v == 0) {
		do {
			*(unsigned int*)((char*)obj + 4) = 3;
			BlockCurrentContext(NULL);
			v = *(unsigned int*)((char*)obj + 0x44);
		} while (v == 0);
	}
	SetIRQInterruptState(priorState);
	*out = v;
	return *(int*)((char*)obj + 0x40);
}
