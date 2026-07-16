#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
ARM int TailCall_02222ddc(void);
extern "C" void func_ov031_0223c078(int, int, int, int);
ARM void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_0222b290(void);

struct Struct0222b22c { unsigned char flag; };
extern Struct0222b22c data_ov031_02290c80;

// USA: func_ov031_0222b22c
ARM void RegisterCallback_0222b22c(void) {
	if (func_ov031_0223c054(1) != 0) {
		return;
	}
	TailCall_02222ddc();
	if (data_ov031_02290c80.flag == 0) {
		func_ov031_0223c078(3, 1, 1, 8);
	}
	func_ov031_0223c078(3, 0, 0x15, 8);
	SetField_022274c0_022274c0((int)func_ov031_0222b290);
}
