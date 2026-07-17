#include <globaldefs.h>

extern void* TailCallElemAtIndex30_0223c7c4(int);
extern unsigned char data_ov031_02250bac;

#pragma optimize_for_size off
// USA: func_ov031_02223440
ARM int MaybeResetFlag_02223440() {
	if (data_ov031_02250bac == 0) return 0;
	TailCallElemAtIndex30_0223c7c4(1);
	data_ov031_02250bac = 0;
	return 1;
}
