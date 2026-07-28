#include <globaldefs.h>
#include "System/ProcessorContext.h"

extern "C" int func_ov031_022008ac(void* a, int b, void* c, void* d, int e, int f);
bool IsContextInactive(ProcessorContext* context);
void MarkContextReadyAndSwitch(ProcessorContext* context);

struct GlobalStruct0224c980_02200aa0 {
	char pad[0x54];
	ProcessorContext* volatile field54;
};

extern GlobalStruct0224c980_02200aa0 data_ov031_0224c980;

// USA: func_ov031_02200aa0  (semantic: CheckAndReadyContext_02200aa0)
#pragma optimize_for_size off
extern "C" ARM void func_ov031_02200aa0(void* a, int b, void* c, void* d) {
	func_ov031_022008ac(a, b, c, d, 0, 0);
	if (data_ov031_0224c980.field54 == NULL) return;
	if (IsContextInactive(data_ov031_0224c980.field54)) return;
	MarkContextReadyAndSwitch(data_ov031_0224c980.field54);
}
