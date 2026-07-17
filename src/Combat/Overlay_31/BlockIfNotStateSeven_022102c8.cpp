#include <globaldefs.h>
#include "System/ProcessorContext.h"

extern void* data_ov031_0224e588;
int IsStateSeven_02210ef8(void);
void SetOrReleaseField4_0221038c(int v);

// USA: func_ov031_022102c8
ARM int BlockIfNotStateSeven_022102c8(void) {
	if (data_ov031_0224e588 == NULL) return 0;
	if (!IsStateSeven_02210ef8()) {
		SetOrReleaseField4_0221038c(1);
		BlockCurrentContext((BlockedContextList*)((char*)data_ov031_0224e588 + 0xa04));
	}
	return IsStateSeven_02210ef8();
}
