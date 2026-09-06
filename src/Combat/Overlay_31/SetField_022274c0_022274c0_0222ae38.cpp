#include <globaldefs.h>

extern "C" void func_ov031_022368e0(void);
extern "C" void func_ov031_02236878(int);
extern void SetOffset1e298_0222785c(int);
ARM void SetField_022274c0_022274c0(int v);
extern "C" void func_ov031_0222ac88(void);

extern unsigned char data_ov031_02290c7c;

// USA: func_ov031_0222ae38
extern "C" ARM void func_ov031_0222ae38(int mode) {
	func_ov031_022368e0();
	if (mode == 0) {
		data_ov031_02290c7c = 1;
		func_ov031_02236878(0x10);
	} else {
		data_ov031_02290c7c = 2;
		func_ov031_02236878(0x12);
	}
	SetOffset1e298_0222785c(0);
	SetField_022274c0_022274c0((int)func_ov031_0222ac88);
}
