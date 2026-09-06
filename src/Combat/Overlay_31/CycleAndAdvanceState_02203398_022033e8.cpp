#include <globaldefs.h>
#include "System/ProcessorContext.h"

void ResetStatusIfEight_0220a9b0(void*);
struct Struct0_02203398;
ARM void CycleAndAdvanceState_02203398(Struct0_02203398* obj);

// USA: func_ov031_022033e8  (semantic: ResetOrAdvanceContext_022033e8)
extern "C" ARM void func_ov031_022033e8(void) {
	void* mgr = *(void**)((char*)data_02111304.activeContext + 0xa4);
	if (mgr == NULL) return;
	if (*((unsigned char*)mgr + 9) != 0) {
		ResetStatusIfEight_0220a9b0(mgr);
	}
	CycleAndAdvanceState_02203398((Struct0_02203398*)mgr);
}
