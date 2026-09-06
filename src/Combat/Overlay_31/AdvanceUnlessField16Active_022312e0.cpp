#include <globaldefs.h>
#include "System/ProcessorContext.h"

extern "C" void func_ov031_02231468(void);
extern "C" void func_ov031_022312a4(void);
extern "C" void func_ov031_022312dc(void);
ARM void AdvanceUnlessField16Active_022312e0(void);

// USA: func_ov031_02231284  (semantic: SleepAndAdvance_02231284)
extern "C" ARM void func_ov031_02231284(void) {
	SleepCurrentContext(0xa);
	func_ov031_02231468();
	func_ov031_022312a4();
	func_ov031_022312dc();
	AdvanceUnlessField16Active_022312e0();
}
