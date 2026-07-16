#include <globaldefs.h>
#include "System/ProcessorContext.h"

extern int data_ov031_02290fd0;
extern ProcessorContext data_ov031_022918dc;
int ForwardGlobal022918bcZeroZero_022403f4(void);

// USA: func_ov031_022403b0
ARM void SetFlagForwardAndAwait_022403b0(void) {
	data_ov031_02290fd0 = 1;
	ForwardGlobal022918bcZeroZero_022403f4();
	AwaitContextCompletion(&data_ov031_022918dc);
}
