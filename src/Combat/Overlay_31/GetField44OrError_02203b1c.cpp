#include <globaldefs.h>
#include "System/ProcessorContext.h"

int GetRemainingOrStatus_0220a800(void*);

// USA: func_ov031_02203b1c
#pragma optimize_for_size off
ARM int GetField44OrError_02203b1c(void) {
	void* mgr = *(void**)((char*)data_02111304.activeContext + 0xa4);
	if (mgr != NULL) {
		if (*((unsigned char*)mgr + 9) != 0) {
			return GetRemainingOrStatus_0220a800(mgr);
		}
		unsigned int field44 = *(unsigned int*)((char*)mgr + 0x44);
		unsigned char byte8 = *((unsigned char*)mgr + 8);
		if (field44 != 0 || byte8 == 4 || byte8 == 10 || byte8 == 11) {
			return field44;
		}
		return -1;
	}
	return 0;
}
