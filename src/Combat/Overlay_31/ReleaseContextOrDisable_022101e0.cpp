#include <globaldefs.h>
#include "System/ProcessorContext.h"

bool IsContextInactive(ProcessorContext* context);
void SetOrReleaseField4_0221038c(int v);
void DisableIMEAndMarkContextReady_02210618(void);

extern void* data_ov031_0224e588;

// USA: func_ov031_022101e0
ARM int ReleaseContextOrDisable_022101e0(void) {
	if (data_ov031_0224e588 == NULL) return 1;
	SetOrReleaseField4_0221038c(2);
	if (!IsContextInactive((ProcessorContext*)((char*)data_ov031_0224e588 + 0xa10))) {
		DisableIMEAndMarkContextReady_02210618();
		return 0;
	}
	UnblockContexts((BlockedContextList*)((char*)data_ov031_0224e588 + 0xa04));
	data_ov031_0224e588 = NULL;
	return 1;
}
