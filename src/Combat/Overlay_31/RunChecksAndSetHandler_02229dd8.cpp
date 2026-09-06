#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
extern int IsField19ZeroOrNull_02222e54(void);
extern void* TailCallElemAtIndex30_0223c7c4(int);
extern "C" void func_ov031_0223cbbc(int, int);
extern void SetField1014_022274d0(int, int);
extern void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_0222aabc(void);

// USA: func_ov031_02229dd8  (semantic: RunChecksAndSetHandler_02229dd8)
extern "C" ARM void func_ov031_02229dd8(void) {
	if (func_ov031_0223c054(0) != 0) return;
	if (IsField19ZeroOrNull_02222e54() == 0) return;

	TailCallElemAtIndex30_0223c7c4(0);

	func_ov031_0223cbbc(0, 0x15);

	SetField1014_022274d0(0, 1);
	SetField_022274c0_022274c0((int)func_ov031_0222aabc);
}
