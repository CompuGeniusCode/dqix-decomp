#include <globaldefs.h>

extern "C" void func_ov031_022297ac(void);
extern "C" void func_ov031_022235a0(int);
extern "C" void func_ov031_02222b0c(int);
extern "C" void func_ov031_02223a64(int);
extern "C" void func_ov031_02236878(int);
extern void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_0222982c(void);

// USA: func_ov031_02229774  (semantic: RunStartupSequenceAndSetHandler_02229774)
extern "C" ARM void func_ov031_02229774(void) {
	func_ov031_022297ac();
	func_ov031_022235a0(0x1e);
	func_ov031_02222b0c(0);
	func_ov031_02223a64(1);
	func_ov031_02236878(0xb);
	SetField_022274c0_022274c0((int)func_ov031_0222982c);
}
