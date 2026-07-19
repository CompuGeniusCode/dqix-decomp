#include <globaldefs.h>

extern "C" void func_ov008_02184878(void* a);
void BlankFunction0208be8c(void);

typedef void (*BlankFn)(void*);

// USA: func_ov017_021b9904
ARM void ForwardTeardownA_021b9904(char* p) {
	void* a = *(void**)(p + 0x118);
	if (a != NULL) func_ov008_02184878(a);
	((BlankFn)BlankFunction0208be8c)(p + 0x30);
}
