#include <globaldefs.h>
#include "System/ProcessorContext.h"

struct GlobalStruct022496fc {
	int field0;
	int field4;
};

extern GlobalStruct022496fc data_ov031_022496fc;

// USA: func_ov031_02207cf0
ARM unsigned int SwapActiveContextPriority_02207cf0() {
	if ((unsigned int)data_ov031_022496fc.field4 >= 0x20) {
		return -1;
	}
	ProcessorContext* ctx = data_02111304.activeContext;
	unsigned int old = GetContextPriority(ctx);
	ChangeContextPriority(ctx, data_ov031_022496fc.field4);
	return old;
}
