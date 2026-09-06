#include <globaldefs.h>
#include "System/ProcessorContext.h"

extern "C" void func_ov031_02231864(void);
extern "C" void func_ov031_022316bc(void);
extern "C" void func_ov031_022316f4(void);
extern "C" void func_ov031_022316f8(void);

// USA: func_ov031_0223169c
ARM void RunFourSteps_0223169c(void) {
	SleepCurrentContext(10);
	func_ov031_02231864();
	func_ov031_022316bc();
	func_ov031_022316f4();
	func_ov031_022316f8();
}
