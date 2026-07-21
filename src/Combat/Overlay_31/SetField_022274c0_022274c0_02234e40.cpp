#include <globaldefs.h>

extern "C" int func_ov031_02237eb0(void);
ARM void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_02234b2c(void);
extern "C" void func_ov031_02234cac(void);
extern "C" void func_ov031_02236878(int);
void ClearField18_02222e80(void);
void SetField1370_022376e4(int val);
void RunThreeInitSteps_02234a90(void);

extern unsigned char data_ov031_02290ce4;

// USA: func_ov031_02234e40
extern "C" ARM void func_ov031_02234e40(void) {
	if (func_ov031_02237eb0() != 0) {
		return;
	}
	if (data_ov031_02290ce4 == 1) {
		SetField_022274c0_022274c0((int)func_ov031_02234b2c);
		return;
	}
	func_ov031_02236878(0xb);
	ClearField18_02222e80();
	data_ov031_02290ce4 = 0;
	SetField1370_022376e4((int)func_ov031_02234cac);
	SetField_022274c0_022274c0((int)RunThreeInitSteps_02234a90);
}
