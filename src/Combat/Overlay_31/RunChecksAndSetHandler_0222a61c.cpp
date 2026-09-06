#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
extern unsigned char data_ov031_02290c74[];
extern int IsField19ZeroOrNull_02222e54(void);
extern void* TailCallElemAtIndex30_0223c7c4(int);
extern "C" void func_ov031_02223440(void);
extern "C" void func_ov031_0223cbbc(int, int);
extern void SetField1014_022274d0(int, int);
extern void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_0222905c(void);
extern "C" void func_ov031_0222aabc(void);

// USA: func_ov031_0222a61c
ARM void RunChecksAndSetHandler_0222a61c(void) {
	if (func_ov031_0223c054(1) != 0) return;
	if (func_ov031_0223c054(0) != 0) return;
	if (IsField19ZeroOrNull_02222e54() == 0) return;

	TailCallElemAtIndex30_0223c7c4(0);

	if (data_ov031_02290c74[1] == 0) {
		func_ov031_02223440();
		func_ov031_0223cbbc(1, 1);
	}
	func_ov031_0223cbbc(0, 0x15);

	if (data_ov031_02290c74[1] == 0) {
		SetField1014_022274d0(0, 1);
		SetField_022274c0_022274c0((int)func_ov031_0222905c);
	} else {
		SetField1014_022274d0(0, 1);
		SetField_022274c0_022274c0((int)func_ov031_0222aabc);
	}
}
