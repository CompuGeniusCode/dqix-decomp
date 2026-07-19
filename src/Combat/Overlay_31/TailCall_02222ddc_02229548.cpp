#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
ARM void TailCall_02222ddc(void);
extern "C" void func_ov031_0223c078(int, int, int, int);
ARM void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_022295ac(void);

struct Struct02229548 { unsigned char idx; unsigned char flag; };
extern Struct02229548 data_ov031_02290c5c;

// USA: func_ov031_02229548  (semantic: CheckFlagThenMaybeTailCallAndSetHandler_02229548)
extern "C" ARM void func_ov031_02229548(void) {
	if (func_ov031_0223c054(1) != 0) {
		return;
	}
	if (data_ov031_02290c5c.flag != 0) {
		TailCall_02222ddc();
	}
	func_ov031_0223c078(3, 1, 1, 8);
	func_ov031_0223c078(3, 0, 0x14, 8);
	SetField_022274c0_022274c0((int)func_ov031_022295ac);
}
