#include <globaldefs.h>
#include "System/ProcessorContext.h"

int IsStateSeven_02210ef8(void);
extern "C" void func_ov031_0221038c(int state);
extern void* data_ov031_0224e588;

// USA: func_ov031_022102c8  (semantic: GuardStateSevenBlock_022102c8)
extern "C" ARM int func_ov031_022102c8(void) {
	if (data_ov031_0224e588 == NULL) {
		return 0;
	}
	if (!IsStateSeven_02210ef8()) {
		func_ov031_0221038c(1);
		BlockCurrentContext((BlockedContextList*)((char*)data_ov031_0224e588 + 0x204 + 0x800));
	}
	return IsStateSeven_02210ef8();
}
