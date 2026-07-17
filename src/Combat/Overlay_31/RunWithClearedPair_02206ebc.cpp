#include <globaldefs.h>
#include "System/Interrupts.h"

extern "C" int func_ov031_02204c84(void* arg);

struct Pair02206ebc {
	unsigned int a;
	unsigned int b;
};

extern Pair02206ebc data_ov031_0224c9e0;

// USA: func_ov031_02206ebc
ARM int RunWithClearedPair_02206ebc(void* arg) {
	int state = DisableIRQInterrupts();
	unsigned int savedA = data_ov031_0224c9e0.a;
	unsigned int savedB = data_ov031_0224c9e0.b;
	data_ov031_0224c9e0.a = 0;
	data_ov031_0224c9e0.b = 0;
	int result = func_ov031_02204c84(arg);
	data_ov031_0224c9e0.a = savedA;
	data_ov031_0224c9e0.b = savedB;
	SetIRQInterruptState(state);
	return result;
}
