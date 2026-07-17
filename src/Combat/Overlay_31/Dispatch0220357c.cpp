#include <globaldefs.h>
#include "System/ProcessorContext.h"

extern "C" int func_ov031_0220a594(unsigned int*, void*);
int WaitForField44_022034ac(unsigned int*, void*);
int WaitOrCycle_02203500(unsigned int*, void*);

// USA: func_ov031_0220357c
#pragma optimize_for_size off
ARM int Dispatch0220357c(unsigned int* out) {
	void* mgr = *(void**)((char*)data_02111304.activeContext + 0xa4);
	if (mgr == NULL) {
		*out = 0;
		return 0;
	}
	unsigned char byte8 = *((unsigned char*)mgr + 8);
	if (byte8 == 10 || byte8 == 11) {
		return WaitForField44_022034ac(out, mgr);
	}
	if (*((unsigned char*)mgr + 9) != 0) {
		return func_ov031_0220a594(out, mgr);
	}
	return WaitOrCycle_02203500(out, mgr);
}
