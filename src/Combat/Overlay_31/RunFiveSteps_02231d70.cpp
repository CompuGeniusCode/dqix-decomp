#include <globaldefs.h>
#include "System/ProcessorContext.h"

extern "C" void func_ov031_02231f54(void);
extern "C" void func_ov031_02231d90(void);
extern "C" void func_ov031_02231dc8(void);
extern "C" void func_ov031_02231dcc(void);

// USA: func_ov031_02231d70
ARM void RunFiveSteps_02231d70(void) {
	SleepCurrentContext(10);
	func_ov031_02231f54();
	func_ov031_02231d90();
	func_ov031_02231dc8();
	func_ov031_02231dcc();
}
