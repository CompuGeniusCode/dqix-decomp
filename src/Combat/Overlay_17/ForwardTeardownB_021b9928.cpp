#include <globaldefs.h>

extern "C" void func_ov008_02184968(void* a);
void BlankFunction0208be90(void);

typedef void (*BlankFn)(void*);

// USA: func_ov017_021b9928
ARM void ForwardTeardownB_021b9928(char* p) {
	void* a = *(void**)(p + 0x118);
	if (a != NULL) func_ov008_02184968(a);
	((BlankFn)BlankFunction0208be90)(p + 0x30);
}
