#include <globaldefs.h>
#include "System/ProcessorContext.h"

int GetRemainingOrStatus_0220a800(char* self);

// USA: func_ov031_02203b1c  (semantic: GetActiveContextRemainingOrStatus_02203b1c)
#pragma optimize_for_size off
extern "C" ARM int func_ov031_02203b1c(void) {
	char* mgr = *(char**)((char*)data_02111304.activeContext + 0xa4);
	if (mgr == NULL) {
		goto ret_zero;
	}
	if (*(unsigned char*)(mgr + 9) != 0) {
		return GetRemainingOrStatus_0220a800(mgr);
	}
	{
		int f44 = *(int*)(mgr + 0x44);
		if (f44 != 0) {
			goto ret_f44;
		}
		if (*(unsigned char*)(mgr + 8) == 4) {
			goto ret_f44;
		}
		{
			unsigned char t = (unsigned char)(*(unsigned char*)(mgr + 8) + 0xf6);
			if (t > 1) {
				goto ret_neg1;
			}
		}
	ret_f44:
		return f44;
	}
ret_neg1:
	return -1;
ret_zero:
	return 0;
}
