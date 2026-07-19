#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
extern "C" void func_020c976c(unsigned int);
void TerminateSystem020ce7a4(void);

// USA: func_ov031_02229bc8  (semantic: CheckFlagsThenTerminate_02229bc8)
extern "C" ARM void func_ov031_02229bc8(void) {
	if (func_ov031_0223c054(1) != 0) return;
	if (func_ov031_0223c054(0) != 0) return;
	func_020c976c(0x1000000);
	TerminateSystem020ce7a4();
}
