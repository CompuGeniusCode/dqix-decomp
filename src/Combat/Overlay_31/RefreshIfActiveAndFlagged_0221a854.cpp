#include <globaldefs.h>
#include "System/ProcessorContext.h"

void RefreshRefIfFlagged_02217e70(char* self);
bool IsContextInactive(ProcessorContext* context);

extern char* data_ov031_0224e69c;

// USA: func_ov031_0221a854  (semantic: RefreshIfActiveAndFlagged_0221a854)
extern "C" ARM void func_ov031_0221a854(void) {
	char* p = data_ov031_0224e69c;
	if (p == NULL || *(int*)(p + 0x1bac) == 0) return;
	if (IsContextInactive((ProcessorContext*)(p + 0x1b40)) != 0) return;
	RefreshRefIfFlagged_02217e70(data_ov031_0224e69c + 8);
}
