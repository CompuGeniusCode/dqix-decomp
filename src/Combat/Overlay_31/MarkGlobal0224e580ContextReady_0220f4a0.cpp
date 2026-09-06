#include <globaldefs.h>
#include "System/ProcessorContext.h"

extern void* data_ov031_0224e580;

// USA: func_ov031_0220f4a0
ARM void MarkGlobal0224e580ContextReady_0220f4a0(void) {
	MarkContextReadyAndSwitch((ProcessorContext*)((char*)data_ov031_0224e580 + 0x34));
}
