#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int arg);
extern "C" void func_ov031_02222bdc(void);
extern "C" int func_ov031_02223440(void);
extern "C" int func_ov031_0223cbbc(int, int);
extern "C" void func_ov031_02233248(void);
extern "C" void func_ov031_02231988(void);

ARM int IsField19ZeroOrNull_02222e54(void);
ARM void* TailCallElemAtIndex30_0223c7c4(int idx);
ARM int CheckStateThenProcess_02227ba4(void);
ARM void SetField1014_022274d0(int a, int b);
ARM void SetField_022274c0_022274c0(int v);

extern unsigned char data_ov031_02290cb0;

// USA: func_ov031_022317a8  (semantic: CheckStateAndDispatchHandler_022317a8)
extern "C" ARM void func_ov031_022317a8(void) {
	if (func_ov031_0223c054(0) != 0) {
		return;
	}
	if (data_ov031_02290cb0 == 0) {
		if (func_ov031_0223c054(1) != 0) {
			return;
		}
	}
	if (IsField19ZeroOrNull_02222e54() == 0) {
		return;
	}
	func_ov031_02222bdc();
	TailCallElemAtIndex30_0223c7c4(0);
	if (data_ov031_02290cb0 == 0) {
		func_ov031_02223440();
		func_ov031_0223cbbc(1, 1);
	}
	CheckStateThenProcess_02227ba4();
	if (data_ov031_02290cb0 == 0) {
		SetField1014_022274d0(2, 1);
		SetField_022274c0_022274c0((int)func_ov031_02233248);
		return;
	}
	SetField1014_022274d0(0, 0);
	SetField_022274c0_022274c0((int)func_ov031_02231988);
}
