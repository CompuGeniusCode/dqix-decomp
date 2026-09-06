#include <globaldefs.h>
#include "System/ProcessorContext.h"

extern void* data_ov031_0224e588;

// USA: func_ov031_022101c4
ARM void MarkGlobal0224e588ContextReady_022101c4(void) {
	MarkContextReadyAndSwitch((ProcessorContext*)((char*)data_ov031_0224e588 + 0xa10));
}
