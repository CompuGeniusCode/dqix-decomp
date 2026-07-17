#include <globaldefs.h>
#include "System/ProcessorContext.h"

extern "C" void func_ov031_022039b0(int, int, int, int);

// USA: func_ov031_02203b8c
ARM void ClearField60_02203b8c(void) {
	void* mgr = *(void**)((char*)data_02111304.activeContext + 0xa4);
	if (mgr == NULL) return;
	int field60 = *(int*)((char*)mgr + 0x60);
	if (field60 == 0) return;
	func_ov031_022039b0(*(int*)((char*)mgr + 0x5c), field60, 0, 0);
	*(int*)((char*)mgr + 0x60) = 0;
}
