#include <globaldefs.h>

extern "C" int func_ov031_02204c84(int a);
unsigned int DisableIRQInterrupts();
unsigned int SetIRQInterruptState(int mask);

struct Data0224c9e0 {
	unsigned int w0;
	unsigned int w1;
};
extern struct Data0224c9e0 data_ov031_0224c9e0;

// USA: func_ov031_02206ebc  (semantic: CallWithClearedState_02206ebc)
extern "C" ARM int func_ov031_02206ebc(int a) {
	unsigned int state = DisableIRQInterrupts();
	unsigned int w0 = data_ov031_0224c9e0.w0;
	unsigned int w1 = data_ov031_0224c9e0.w1;
	data_ov031_0224c9e0.w0 = 0;
	data_ov031_0224c9e0.w1 = 0;
	int result = func_ov031_02204c84(a);
	data_ov031_0224c9e0.w0 = w0;
	data_ov031_0224c9e0.w1 = w1;
	SetIRQInterruptState(state);
	return result;
}
