#include <globaldefs.h>

extern int TailCallForward_0223e2e0(int, void*);
extern "C" void func_ov031_0223da58(void*);
extern "C" void func_ov031_0223cf70(void*);
extern void* data_ov031_02250ba4;

// USA: func_ov031_02222bdc
ARM void ForwardAndCleanup_02222bdc() {
	TailCallForward_0223e2e0(1, *(void**)data_ov031_02250ba4);
	void* g = data_ov031_02250ba4;
	void* arg = *(void**)((char*)g + 4);
	func_ov031_0223da58(arg);
	func_ov031_0223cf70(&data_ov031_02250ba4);
}
