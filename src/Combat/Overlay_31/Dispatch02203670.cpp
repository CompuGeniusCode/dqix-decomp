#include <globaldefs.h>
#include "System/ProcessorContext.h"

void ReleaseHandleIfFull_0220a66c(void*);
extern "C" void func_ov031_022035e0(void*);

// USA: func_ov031_02203670
ARM void Dispatch02203670(void) {
	void* mgr = *(void**)((char*)data_02111304.activeContext + 0xa4);
	if (mgr == NULL) return;
	if (*((unsigned char*)mgr + 9) != 0) {
		ReleaseHandleIfFull_0220a66c(mgr);
	} else {
		func_ov031_022035e0(mgr);
	}
}
